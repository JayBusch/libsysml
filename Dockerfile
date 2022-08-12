FROM debian:stable-slim as dev-env

RUN apt update &&\
    apt install -y --no-install-recommends \
    	make \
        build-essential \
        autoconf \
        automake \
        libtool \
        pkg-config \
        apt-transport-https \
        ca-certificates \
        software-properties-common \
        wget \
        git \
        curl \
        gnupg \
        zlib1g-dev \
        swig \
        vim \
        gdb \
        valgrind \
	clang \
	lldb \
        locales \
        locales-all \
	libfontconfig1-dev \
	libboost-all-dev \
	sudo \
	python \
	libjpeg-dev \
	libharfbuzz-dev \
	mesa-utils \
	libgl-dev \
	libwebp-dev \
	libxext-dev \
	libsdl2-dev \
	tao-pegtl-dev \
	libstdc++6-10-dbg \
	cmake &&\
    apt clean

FROM dev-env as app

COPY install_build_deps.sh install_build_deps.sh
COPY dependencies dependencies

RUN ./install_build_deps.sh

COPY src src
COPY CMakeLists.txt CMakeLists.txt
COPY build.sh build.sh

FROM app as build

RUN ./build.sh

ENV LC_ALL en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US.UTF-8

