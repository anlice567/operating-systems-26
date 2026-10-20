//Here is what I found in var/log/apport.log after interrupting the process by control+C and control+\
//INFO: apport (pid 4248) 2026-10-20 08:51:58,391: called for global pid 4247, signal 3, core limit 18446744073709551615, dump mode 1
//ERROR: apport (pid 4248) 2026-10-20 08:51:58,391: ignoring implausibly big core limit, treating as unlimited
//INFO: apport (pid 4248) 2026-10-20 08:51:58,392: writing core dump to /var/lib/apport/coredump/core._home_anfisa258_t.1000.a9c906d2-34a7-4a1b-b9d1-e3fd2791ac49.4247.50665 (limit: -1)
#include <stdio.h>
int main() {
    while (1) {
        printf("%s","Hello world!");
    }
}
