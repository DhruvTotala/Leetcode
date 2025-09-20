#include <bits/stdc++.h>
using namespace std;

struct Packet {
    int source;
    int destination;
    int timestamp;
};

struct PacketKey {
    int source, destination, timestamp;

    bool operator==(const PacketKey &other) const {
        return source == other.source &&
               destination == other.destination &&
               timestamp == other.timestamp;
    }
};

struct PacketKeyHash {
    size_t operator()(const PacketKey &p) const {
        return (1LL * p.source * 10000019 + 1LL * p.destination * 1009 + p.timestamp);
    }
};

class Router {
private:
    int memoryLimit;
    deque<Packet> packets;
    unordered_set<PacketKey, PacketKeyHash> packetSet;
    unordered_map<int, vector<int>> destToTimestamps;
    unordered_map<int, int> destToStartIndex; // Tracks valid range after removals

    void removeOldestPacket() {
        if (packets.empty()) return;
        Packet oldest = packets.front();
        packets.pop_front();

        PacketKey key { oldest.source, oldest.destination, oldest.timestamp };
        packetSet.erase(key);

        // Move startIndex forward for this destination
        int& startIndex = destToStartIndex[oldest.destination];
        auto& timestamps = destToTimestamps[oldest.destination];
        while (startIndex < (int)timestamps.size() && timestamps[startIndex] != oldest.timestamp) {
            startIndex++;
        }
        if (startIndex < (int)timestamps.size()) startIndex++;
    }

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int source, int destination, int timestamp) {
        PacketKey key { source, destination, timestamp };
        if (packetSet.find(key) != packetSet.end()) return false;
        
        if ((int)packets.size() >= memoryLimit) {
            removeOldestPacket();
        }

        packets.push_back({source, destination, timestamp});
        packetSet.insert(key);
        destToTimestamps[destination].push_back(timestamp); // Appending in order
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty()) return {};
        Packet pkt = packets.front();
        packets.pop_front();

        PacketKey key { pkt.source, pkt.destination, pkt.timestamp };
        packetSet.erase(key);

        // Move start index forward for this destination
        int& startIndex = destToStartIndex[pkt.destination];
        auto& timestamps = destToTimestamps[pkt.destination];
        while (startIndex < (int)timestamps.size() && timestamps[startIndex] != pkt.timestamp) {
            startIndex++;
        }
        if (startIndex < (int)timestamps.size()) startIndex++;

        return { pkt.source, pkt.destination, pkt.timestamp };
    }

    int getCount(int destination, int startTime, int endTime) {
        if (destToTimestamps.find(destination) == destToTimestamps.end()) return 0;
        
        auto& timestamps = destToTimestamps[destination];
        int startIndex = destToStartIndex[destination];
        
        auto itLow = lower_bound(timestamps.begin() + startIndex, timestamps.end(), startTime);
        auto itHigh = upper_bound(timestamps.begin() + startIndex, timestamps.end(), endTime);
        return distance(itLow, itHigh);
    }
};