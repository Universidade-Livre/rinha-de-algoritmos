FROM python:3.11.7-alpine3.18

# Install the hyperfine package and networkx
RUN apk --no-cache add hyperfine jq \
    && pip install networkx==3.2

WORKDIR /app
COPY . /app

# Make the script executable
RUN chmod +x /app/runtime.sh

# Run the script as the default command
CMD ["/app/runtime.sh"]
