FROM rust:1.75-alpine3.18

# Install the hyperfine package
RUN apk --no-cache add hyperfine jq

WORKDIR /app
COPY . /app

# Convert line endings of the script to Unix format and executable
RUN dos2unix /app/run_commands.sh
RUN chmod +x /app/run_commands.sh

# Run the script as the default command
CMD ["/app/run_commands.sh"]