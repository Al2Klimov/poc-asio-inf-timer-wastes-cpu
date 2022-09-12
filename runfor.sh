#!/bin/bash

set -exo pipefail

P=$$

(
	sleep "$1"
	kill $P
) &

exec "${@:2}"
