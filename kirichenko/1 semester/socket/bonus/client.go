package main

import (
    "net"
    "fmt"
    "bufio"
    "os"
)

func listenServer(conn net.Conn) {
    for {
        message, _ := bufio.NewReader(conn).ReadString('\n')
        if message != "" {
            fmt.Println(message[:len(message) - 1])
        }
    }
}

func main() {
    conn, _ := net.Dial("tcp", "127.0.0.1:1234")
    go listenServer(conn)
    for {
        reader := bufio.NewReader(os.Stdin)
        fmt.Print("Text to send: ")
        text, _ := reader.ReadString('\n')
        fmt.Fprintf(conn, text + "\n")
    }
}