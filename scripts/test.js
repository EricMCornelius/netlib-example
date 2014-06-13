#!/usr/bin/env node

var http = require('http');

http.createServer(function (req, res) {
  console.log(req);
  res.writeHead(200, {'Content-Type': 'text/plain'});
  res.end("pong");
}).listen(9400);
