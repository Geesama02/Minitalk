# Minitalk

Minitalk is a project part of the 42 School curriculum. It focuses on inter-process communication using signals. The goal is to create a simple client-server architecture where the client sends messages to the server, and the server prints the received messages.

## Overview

The Minitalk project revolves around creating a communication system between two processes, a client, and a server. The communication is achieved through the use of signals. The client converts strings to binary and sends them to the server using signals, and the server decodes the signals to reconstruct the original messages.

## Features

- Simple client-server architecture
- Inter-process communication using signals
- Message encoding and decoding

## Getting Started

### Prerequisites

- A Unix-like operating system
- A C compiler (e.g., GCC)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/minitalk.git
Navigate to the project directory:

    cd minitalk
Compile the source code:

    make
Usage
Start the server:

    ./server
Start the client:

    ./client [server_pid] [message]
Replace [server_pid] with the PID of the server process, and [message] with the message you want to send.

Examples
Start the server:

    ./server
In another terminal, start the client:

    ./client [server_pid] Hello, Minitalk!
Replace [server_pid] with the actual PID of the server process.

The server should display the received message.

Bonus

The bonus part of the project involves handling acknowledgments from the server. The client sends an acknowledgment signal to the server after successfully transmitting a message. The server, upon receiving the acknowledgment, prints a confirmation message.

Also with the bonus the server is able to handle unicode messages too (emojis , etc...)

To use the bonus features, simply compile the bous part using "make bonus" then run the client_bonus and server_bonus executables instead of the regular ones.

Contributing

Contributions are welcome! If you'd like to contribute to the project,
