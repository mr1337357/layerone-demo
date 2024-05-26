package main

import (
    "strconv"
)

type Line struct
{
    lineno uint16
    size uint8 /*size of whole struct */
    cmd uint8 /*parsed command */
    arguments string
}

type Program struct
{
    code [65536]Line
}

func AddLine(p Program, s string) {
    var l Line
    lineno, _ := strconv.ParseInt(s,10,16)
    l.lineno = uint16(lineno)
	l.cmd = 0 //todo
	l.size = 4
}
