FROM clojure:latest

# Set the working directory to /app
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Install additional dependencies using lein
RUN lein deps

# Build the Clojure application
RUN lein uberjar

CMD ["java", "-jar", "target/plantation-profit-0.1.0-SNAPSHOT-standalone.jar"]