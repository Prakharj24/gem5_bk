/*
 * ghb.hh
 *
 *  Created on: 20-Apr-2015
 *      Author: biswa
 */

#ifndef _MEM_CACHE_PREFETCH_GHB_HH_
#define _MEM_CACHE_PREFETCH_GHB_HH_

#include <climits>

#include "mem/cache/prefetch/base.hh"
#include "params/DepthGHBPrefetcher.hh"

class GHBPrefetcher : public BasePrefetcher
{
  protected:
    static const int Max_Contexts = 64;
    class IndexTableEntry {
      public:
        Addr deltaAddr;
        uint16_t GHBPointer;
        uint16_t confidence;
    };

    Addr *lastMissAddr[Max_Contexts];

    std::list<IndexTableEntry*> Index_Table[Max_Contexts];

    class GHB
    {
      public:
        Addr missAddr;
        int16_t LinkPointer;
    };

    std::list<GHB*> GHB_Fifo[Max_Contexts];

  public:

    GHBPrefetcher(const GHBPrefetcherParams *p)
        : QueuedPrefetcher(p)
    {
    }

    ~GHBPrefetcher() {}

    void calculatePrefetch(PacketPtr &pkt, std::Vector<Addr> &addresses);
};

#endif /* __MEM_CACHE_PREFETCH_GHB_PREFETCHER_HH__ */
