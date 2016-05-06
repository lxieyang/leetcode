awk '
{
    for(i = 1; i <= NF; i++) {
        a[NR, i] = $i
    }
}
NF > p { p = NF }
END {
    for(j = 1; j <= p; j++) {
        str = a[1, j]
        for(k = 2; k <= NR; k++) {
            str = str " " a[k, j]
        }
        print str
    }
}' file.txt
