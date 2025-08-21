FROM ubuntu:24.04 AS base
WORKDIR /eval

# Bootstrap the environment
COPY .. ./
RUN ./bootstrap.sh

# RUN chmod 777 /root/.cargo/bin/*
# RUN ln -s $HOME/.cargo/env /etc/profile.d/cargo_env.sh

# Configure the user
RUN mkdir /home/docker
RUN useradd -u 998 -m -d /home/docker docker
RUN adduser docker sudo
RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
RUN chown docker:docker /home/docker; chmod 777 /home/docker

USER docker
ENV HOME=/home/docker

# ENV PATH="/root/.cargo/bin:${PATH}"

# Execute the experiments from the mounted /eval folder. Should be mounted!!
ENTRYPOINT [ "/eval/entrypoint.sh" ]
