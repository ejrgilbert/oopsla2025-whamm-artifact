class TagElement {
    constructor(valid, tag, age) {
        this.valid = valid;
        this.tag = tag;
        this.age = age;
    }
}

class LRUResult {
    static Hit(tag) {
        return { type: 'Hit', tag };
    }

    static Miss(tag, is_evict, evict) {
        return { type: 'Miss', tag, is_evict, evict };
    }
}

class TagStoreEntry {
    constructor(assoc) {
        this.elems = new Array(assoc).fill(null).map(() => new TagElement(false, 0, 0));
    }

    isElemValid(t) {
        return t.valid;
    }

    accessUpdate(tag) {
        let repIdx = -1;
        let isHit = false;
        let repInvalid = false;
        let maxAge = 0;

        let result;

        for (let i = 0; i < this.elems.length; i++) {
            if (this.elems[i].valid) {
                if (this.elems[i].tag === tag) {
                    // Check for Hit; reset age
                    isHit = true;
                    this.elems[i] = new TagElement(true, tag, 0);
                } else {
                    if (!repInvalid && this.elems[i].age >= maxAge) {
                        // Track oldest element for eviction as long as
                        // there is no invalid element to replace
                        maxAge = this.elems[i].age;
                        repIdx = i;
                    }
                    // Increment age of all valid elements besides hit
                    this.elems[i] = new TagElement(this.elems[i].valid, this.elems[i].tag, this.elems[i].age + 1);
                }
            } else {
                // There exists an invalid element to fill for miss
                repInvalid = true;
                repIdx = i;
            }
        }

        if (isHit) {
            result = LRUResult.Hit(tag);
        } else if (repInvalid) {
            this.elems[repIdx] = new TagElement(true, tag, 0);
            result = LRUResult.Miss(tag, false, 0);
        } else {
            // All elements are valid and no hit; evict with LRU
            const evictTag = this.elems[repIdx].tag;
            this.elems[repIdx] = new TagElement(true, tag, 0);
            result = LRUResult.Miss(tag, true, evictTag);
        }

        return result;
    }
}

class CacheInstance {
    constructor(assoc, blockBits, indexBits, tagBits) {
        this.tagBits = tagBits;
        this.blockBits = blockBits;
        this.indexBits = indexBits;

        if ((tagBits + indexBits + blockBits) !== 32) {
            console.error("Cache parameters do not add up to 32 bits.");
        }

        this.assoc = assoc;
        this.indexSize = 1 << indexBits;
        this.blockSize = 1 << blockBits;

        this.tagStore = new Array(this.indexSize).fill(null).map(() => new TagStoreEntry(assoc));
    }

    access(addr) {
        let offset = addr & ((1 << this.blockBits) - 1);
        addr >>= this.blockBits;
        let index = addr & ((1 << this.indexBits) - 1);
        addr >>= this.indexBits;
        let tagVal = addr & ((1 << this.tagBits) - 1);

        return this.tagStore[index].accessUpdate(tagVal);
    }
}

class CacheCounter {
    constructor() {
        // The map will store tuples (fn, pc) -> {hit, miss}
        this.cacheMap = new Map();
    }

    incrementHit(fn, pc) {
        const key = `${fn}-${pc}`;
        
        if (!this.cacheMap.has(key)) {
            this.cacheMap.set(key, { hit: 0, miss: 0 });
        }
        
        const counters = this.cacheMap.get(key);
        counters.hit += 1;
    }

    incrementMiss(fn, pc) {
        const key = `${fn}-${pc}`;

        if (!this.cacheMap.has(key)) {
            this.cacheMap.set(key, { hit: 0, miss: 0 });
        }

        const counters = this.cacheMap.get(key);
        counters.miss += 1; 
    }

}

{
	const cache = new CacheInstance(4, 7, 11, 14);
	const log = new CacheCounter();

	function access({func, instr}, {addr, offset}, op, write) {
		const eff = addr + offset;
		const result = cache.access(eff);
		if (result.type == "Hit") {
			log.incrementHit(func, instr);
		} else { // miss
			log.incrementMiss(func, instr);
		}
	};

	Wasabi.analysis = {
		load(loc, op, memarg) { access(loc, memarg, op, false) },
		store(loc, op, memarg) { access(loc, memarg, op, true) },
	};

	Wasabi.analysisResult = () => {
		// Convert the map entries into an array and sort by fn and pc
		const sortedResults = Array.from(log.cacheMap.entries()).sort((a, b) => {
		    const [fnA, pcA] = a[0].split('-').map(Number);
		    const [fnB, pcB] = b[0].split('-').map(Number);

		    // Sort primarily by fn, and then by pc
		    if (fnA !== fnB) return fnA - fnB;
		    return pcA - pcB;
		});

		sortedResults.forEach(([key, { hit, miss }]) => {
		    const [fn, pc] = key.split('-').map(Number);
		    console.log(`func ${fn}: +${pc}:\t${hit}\t${miss}`);
		});
	}
}
