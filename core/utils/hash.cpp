#include "hash.h"

namespace MurmurHash {
    //-----------------------------------------------------------------------------
    // MurmurHash2, 64-bit versions, by Austin Appleby

    // The same caveats as 32-bit MurmurHash2 apply here - beware of alignment 
    // and endian-ness issues if used across multiple platforms.

    // 64-bit hash for 64-bit platforms

    const Lewzen::HASH_CODE MurmurHash64A ( const void * key, int len, unsigned int seed )
    {
        const Lewzen::HASH_CODE m = 0xc6a4a7935bd1e995;
        const int r = 47;

        Lewzen::HASH_CODE h = seed ^ (len * m);

        const Lewzen::HASH_CODE * data = (const Lewzen::HASH_CODE *)key;
        const Lewzen::HASH_CODE * end = data + (len/8);

        while(data != end)
        {
            Lewzen::HASH_CODE k = *data++;

            k *= m; 
            k ^= k >> r; 
            k *= m; 
            
            h ^= k;
            h *= m; 
        }

        const unsigned char * data2 = (const unsigned char*)data;

        switch(len & 7)
        {
        case 7: h ^= Lewzen::HASH_CODE(data2[6]) << 48;
        case 6: h ^= Lewzen::HASH_CODE(data2[5]) << 40;
        case 5: h ^= Lewzen::HASH_CODE(data2[4]) << 32;
        case 4: h ^= Lewzen::HASH_CODE(data2[3]) << 24;
        case 3: h ^= Lewzen::HASH_CODE(data2[2]) << 16;
        case 2: h ^= Lewzen::HASH_CODE(data2[1]) << 8;
        case 1: h ^= Lewzen::HASH_CODE(data2[0]);
                h *= m;
        };
    
        h ^= h >> r;
        h *= m;
        h ^= h >> r;

        return h;
    } 


    // 64-bit hash for 32-bit platforms

    const Lewzen::HASH_CODE MurmurHash64B ( const void * key, int len, unsigned int seed )
    {
        const unsigned int m = 0x5bd1e995;
        const int r = 24;

        unsigned int h1 = seed ^ len;
        unsigned int h2 = 0;

        const unsigned int * data = (const unsigned int *)key;

        while(len >= 8)
        {
            unsigned int k1 = *data++;
            k1 *= m; k1 ^= k1 >> r; k1 *= m;
            h1 *= m; h1 ^= k1;
            len -= 4;

            unsigned int k2 = *data++;
            k2 *= m; k2 ^= k2 >> r; k2 *= m;
            h2 *= m; h2 ^= k2;
            len -= 4;
        }

        if(len >= 4)
        {
            unsigned int k1 = *data++;
            k1 *= m; k1 ^= k1 >> r; k1 *= m;
            h1 *= m; h1 ^= k1;
            len -= 4;
        }

        switch(len)
        {
        case 3: h2 ^= ((unsigned char*)data)[2] << 16;
        case 2: h2 ^= ((unsigned char*)data)[1] << 8;
        case 1: h2 ^= ((unsigned char*)data)[0];
                h2 *= m;
        };

        h1 ^= h2 >> 18; h1 *= m;
        h2 ^= h1 >> 22; h2 *= m;
        h1 ^= h2 >> 17; h1 *= m;
        h2 ^= h1 >> 19; h2 *= m;

        Lewzen::HASH_CODE h = h1;

        h = (h << 32) | h2;

        return h;
    }
}

namespace Lewzen {
    const unsigned int HASH_SEED = 0xbf378d83LL;
    const Lewzen::HASH_CODE str_hash(const std::string &str) {
        return MurmurHash::MurmurHash64B(str.c_str(), str.size(), HASH_SEED);
    }
}