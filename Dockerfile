FROM silkeh/clang:17

RUN apt-get update && \
    apt-get install -y make cmake vim gdb git locales curl wget && \
    rm -rf /var/lib/apt/lists/*

# 設定語系為 UTF-8 (避免 debugger 輸出亂碼)
RUN locale-gen en_US.UTF-8
ENV LANG=en_US.UTF-8
ENV LANGUAGE=en_US:en8
ENV LC_ALL=en_US.UTF-8

WORKDIR /app

CMD ["/bin/bash"]