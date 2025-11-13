# System-Monitor
Tool to display system metrics for Raspberry Pi 5

# Example
$ curl -s http://pi:9100/metrics
# HELP cpu_seconds_total Cumulative CPU time by mode.
# TYPE cpu_seconds_total counter
cpu_seconds_total{cpu="0",mode="user"} 12543.08
cpu_seconds_total{cpu="0",mode="system"} 2345.12
cpu_seconds_total{cpu="0",mode="idle"} 456789.33
cpu_seconds_total{cpu="1",mode="user"} 11987.42
...

# HELP node_load1 1-minute load average.
# TYPE node_load1 gauge
node_load1 0.42
node_load5 0.31
node_load15 0.28

# HELP memory_bytes Memory statistics from /proc/meminfo.
# TYPE memory_bytes gauge
memory_bytes{type="MemTotal"} 8.57182208e+09
memory_bytes{type="MemFree"} 5.21474048e+09
memory_bytes{type="Buffers"} 1.2457984e+08
memory_bytes{type="Cached"} 2.0135936e+09

# HELP fs_bytes Filesystem size metrics.
# TYPE fs_bytes gauge
fs_bytes{mount="/",fstype="ext4",state="total"} 6.3645696e+10
fs_bytes{mount="/",fstype="ext4",state="free"}  3.21490944e+10
fs_bytes{mount="/",fstype="ext4",state="avail"} 3.1049728e+10

# Exporter self-metrics
# HELP exporter_scrape_duration_seconds Time to render /metrics.
# TYPE exporter_scrape_duration_seconds summary
exporter_scrape_duration_seconds_count 37
exporter_scrape_duration_seconds_sum 0.031