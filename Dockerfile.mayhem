FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y mesa-utils xvfb libgl1 freeglut3-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libxext-dev build-essential cmake

COPY . /repo
WORKDIR /repo/build
RUN cmake ..
RUN make -j8

FROM ubuntu:22.04 as package
COPY --from=builder /repo/bin/yconvert /
