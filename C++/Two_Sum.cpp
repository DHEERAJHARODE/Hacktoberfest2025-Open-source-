   fun twoSum(nums: IntArray, target: Int): IntArray {
        val hashMap = mutableMapOf() // value to index
        
        for((i,v) in nums.withIndex()) {
            val diff = target -v
            val indexForDiffValue = hashMap.get(diff)

            indexForDiffValue?.let {
                return@twoSum intArrayOf(indexForDiffValue, i)
            }
            
            hashMap[v] = i 
        }
        
        throw IllegalStateException("no solution found")
    }
}
