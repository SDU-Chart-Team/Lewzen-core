#ifndef __LZ_UTILS_DS__
#define __LZ_UTILS_DS__
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

namespace Lewzen {
    /**
    * Ordered Map
    */
    template<typename K, typename V, typename Compare=std::less<K>>
    using ordered_map = __gnu_pbds::tree<
        K,
        V,
        Compare,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;
}
#endif