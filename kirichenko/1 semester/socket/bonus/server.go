package main

import (
    "net"
    "fmt"
    "bufio"
    "strings"
)

func reply(message string, conn net.Conn, clients *[]net.Conn) {
    addr := conn.RemoteAddr().String()
    for _, client := range *clients {
        if client != conn {
            client.Write([]byte(addr[:strings.Index(addr, ":")] + ": " + message + "\n"))
        }
    }
}

func handleConnection(conn net.Conn, clients *[]net.Conn) {
    fmt.Println("Connected: " + conn.RemoteAddr().String())
    *clients = append(*clients, conn)

    for {
        message, _ := bufio.NewReader(conn).ReadString('\n')
        if message != "" {
            message = message[:len(message) - 1]
            go reply(message, conn, clients)
            fmt.Println("Message from: " + conn.RemoteAddr().String() + "; " + message)
        } else {
            var i int
            for z, client := range *clients {
                if client == conn {
                    i = z
                    break
                }
            }
            *clients = append((*clients)[:i], (*clients)[i + 1:]...)
            fmt.Println("Disconnected: " + conn.RemoteAddr().String())
            return
        }
    }
}

func main() {
    var clients []net.Conn
    ln, _ := net.Listen("tcp", ":1234")

    for {
        conn, _ := ln.Accept()

        go handleConnection(conn, &clients)
    }
}