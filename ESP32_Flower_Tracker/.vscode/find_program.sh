#!/bin/bash
find "${1:-.pio/build}" -maxdepth 2 -type f -name "program" | head -1