#!/usr/bin/env python3

import webbrowser
import http.server
import socketserver

def run_local_server():
    port = 8000
    handler = http.server.SimpleHTTPRequestHandler

    socketserver.TCPServer.allow_reuse_address = True

    with socketserver.TCPServer(("", port), handler) as httpd:
        print("Serving at port %d" % port)
        httpd.serve_forever()

    webbrowser.open_new_tab("localhost:%d" % port)

if __name__ == "__main__":
    run_local_server()
