---
tags: [c, cybersec, hacking]
---

# lab scope — only systems you may touch

Hacking skill is technique plus **authorization**. Same tools, different legality: your lab / HTB / bug bounty in scope vs random hosts on the internet.

## Rules for this pack

1. Run every demo against **local toys** you compile, or hosts you are **explicitly allowed** to test (HTB, your VMs, written RoE).
2. `scanme.nmap.org` only when you mean a polite public lab probe, and keep it light.
3. No scanning, exploiting, or credential stuffing against systems outside scope. Ever.
4. Notes teach **how breaks work** so you can find and fix them. They are not a license to attack.

You already work authorized targets (HTB, HackerOne, certs under `~/github/applier`). This pack stays in that lane.

## Replicate mindset

Before any probe, answer on paper:

```text
target: _______________
permission: (lab | RoE | bounty scope | none)
goal: (learn X | find Y | report Z)
stop if: out of scope / unexpected prod impact
```

If permission is `none`, stop. Technique practice waits for a lab.

## In the wild — Nmap legal note

Nmap's own docs stress permission and abuse:

```text
# From nmap.org legal concerns (paraphrase for study):
# Scanning systems without permission can be illegal or against ToS.
# Use lab networks, your own hosts, or explicitly authorized targets.
```

Ref: https://nmap.org/book/legal-issues.html

## Try

Pick one authorized target you already use (HTB machine IP, local VM). Write the four-line scope card above. Keep it next to this folder.
