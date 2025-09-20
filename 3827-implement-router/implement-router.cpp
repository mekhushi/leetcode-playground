#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int source, destination, timestamp;
    bool operator==(const Packet& o) const {
        return source == o.source && destination == o.destination && timestamp == o.timestamp;
    }
};

struct PacketHash {
    size_t operator()(const Packet& p) const {
        return ((size_t)p.source * 1315423911u) ^ ((size_t)p.destination * 2654435761u) ^ ((size_t)p.timestamp * 97531u);
    }
};

class Router {
public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}
    bool addPacket(int s, int d, int t) {
        Packet p{s,d,t};
        if (uniquePackets.count(p)) return false;
        if ((int)packetQueue.size() == memoryLimit) forwardPacket();
        packetQueue.push(p); uniquePackets.insert(p);
        dest[d].push_back(t);
        return true;
    }
    vector<int> forwardPacket() {
        if (packetQueue.empty()) return {};
        Packet p = packetQueue.front(); packetQueue.pop(); uniquePackets.erase(p);
        auto& dq = dest[p.destination]; if (!dq.empty() && dq.front() == p.timestamp) dq.pop_front();
        return {p.source, p.destination, p.timestamp};
    }
    int getCount(int d, int l, int r) {
        auto it = dest.find(d); if (it == dest.end()) return 0;
        auto& ts = it->second;
        auto lo = lower_bound(ts.begin(), ts.end(), l);
        auto hi = upper_bound(ts.begin(), ts.end(), r);
        return hi - lo;
    }
private:
    int memoryLimit;
    unordered_set<Packet, PacketHash> uniquePackets;
    queue<Packet> packetQueue;
    unordered_map<int, deque<int>> dest;
};
