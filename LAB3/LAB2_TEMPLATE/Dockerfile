FROM alpine:latest AS build
RUN apk add --no-cache g++ cmake make
WORKDIR /build
COPY src/ ./
RUN cmake . && make

FROM alpine:latest
RUN apk add --no-cache libstdc++ curl
WORKDIR /app
COPY --from=build /build/app .
EXPOSE 8080
ENTRYPOINT ["./app"]