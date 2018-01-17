#!/bin/sh
export DYLD_LIBRARY_PATH="/Users/stmartin/github/malloc"
export DYLD_INSERT_LIBRARIES="/Users/stmartin/github/malloc/libft_malloc.so"
export DYLD_FORCE_FLAT_NAMESPACE="1"
$@
