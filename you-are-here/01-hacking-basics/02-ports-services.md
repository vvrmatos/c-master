---
tags: [c, cybersec, hacking]
---

# ports and services — the attack surface map

A **port** is a 16-bit number on a host. A **service** is whatever process accepted the connection. Recon answers: what is listening, and what speaks there?

## Common lab map

| Port | Usual service | Why attackers care |
|------|---------------|--------------------|
| 22 | ssh | auth, keys, old algos |
| 80/443 | http(s) | apps, injections, files |
| 445 | smb | shares, auth (Windows) |
| 3306 | mysql | DB creds, SQLi pivot |
| 8080 | http-alt | forgotten admin UIs |

Numbers lie. 22 might not be ssh. Always **confirm** (banner, probe, docs).

## Replicate — tiny port DB (you already built the parser)

Feed a mini services file (same skill as `00-input-reading/09`):

```text
# lab-only map
ssh 22/tcp
http 80/tcp
https 443/tcp
mysql 3306/tcp
```

Parse with your `09-parse-services-line` program, or:

```bash
awk '!/^#/ && NF { print $2 "\t" $1 }' <<'EOF'
ssh 22/tcp
http 80/tcp
https 443/tcp
mysql 3306/tcp
EOF
```

## Try

```bash
grep -E '^(ssh|http|https|domain|mysql)\s' /etc/services | head
```

On a **lab** host you own: list listeners (macOS):

```bash
netstat -anv | grep LISTEN
# or
lsof -nP -iTCP -sTCP:LISTEN
```

## In the wild — Nmap services DB

Nmap ships `nmap-services` (name, port/proto, frequency). `--top-ports` is just "most common listeners first".

```c
/* nmap services.cc — NPSL (shape only) */
res = sscanf(line, "%127s %hu/%15s %31s",
             servicename, &portno, proto, ratio_str);
```

Ref: https://github.com/nmap/nmap/blob/master/services.cc
