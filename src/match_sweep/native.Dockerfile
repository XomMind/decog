FROM debian:bookworm AS compiler
ENV DEBIAN_FRONTEND=noninteractive WINEDEBUG=-all
RUN apt-get update && apt-get install -y --no-install-recommends wine wine32 python3 python3-pefile python3-capstone ca-certificates && rm -rf /var/lib/apt/lists/*
ADD toolchain.tar.gz /
COPY project /root/.wine/drive_c/_/_RL/COGMIND/_cogmind
RUN mkdir -p /root/.wine/drive_c/_/_RL/Protobuffer && rm -rf /root/.wine/drive_c/_/_RL/Protobuffer/protobuf-3.5.1 && ln -s /root/.wine/drive_c/_/_RL/COGMIND/_cogmind/3rdparty/protobuf-3.5.1 /root/.wine/drive_c/_/_RL/Protobuffer/protobuf-3.5.1
WORKDIR /root/.wine/drive_c/_/_RL/COGMIND/_cogmind
RUN python3 tools/sources.py > /tmp/sources && xargs python3 tools/ltcg.py build/native < /tmp/sources > /tmp/build.log 2>&1 || { cat /tmp/build.log; exit 1; }
RUN mkdir /result && cp build/native/match.dll build/native/match.map /tmp/build.log /result/
FROM scratch AS artifacts
COPY --from=compiler /result/ /
