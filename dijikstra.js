
function dijkstra(graph, source) {
  const dist = {}
  const prev = {}
  const visited = new Set()

  // Initialize
  for (const node in graph) {
    dist[node] = Infinity
    prev[node] = null
  }
  dist[source] = 0

  while (true) {
    // pick unvisited node with smallest dist
    let u = null
    let bestDist = Infinity
    for (const node in graph) {
      if (!visited.has(node) && dist[node] < bestDist) {
        bestDist = dist[node]
        u = node
      }
    }
    if (u === null) break  // no reachable unvisited nodes left

    visited.add(u)

    for (const edge of graph[u]) {
      const { v, weight } = edge
      if (visited.has(v)) continue
      const alt = dist[u] + weight
      if (alt < dist[v]) {
        dist[v] = alt
        prev[v] = u
      }
    }
  }

  return { dist, prev }
}

/**
 * Reconstruct shortest path from source → target using prev map.
 */
function reconstructPath(prev, target) {
  const path = []
  let u = target
  while (u !== null) {
    path.unshift(u)
    u = prev[u]
  }
  return path
}

// Example usage
if (require.main === module) {
  const graph = {
    A: [ { v: 'B', weight: 2 }, { v: 'C', weight: 5 } ],
    B: [ { v: 'A', weight: 2 }, { v: 'C', weight: 1 }, { v: 'D', weight: 4 } ],
    C: [ { v: 'A', weight: 5 }, { v: 'B', weight: 1 }, { v: 'D', weight: 1 } ],
    D: [ { v: 'B', weight: 4 }, { v: 'C', weight: 1 } ],
  }
  const { dist, prev } = dijkstra(graph, 'A')
  console.log('Distances:', dist)
  console.log('Path A → D:', reconstructPath(prev, 'D'))
}

module.exports = { dijkstra, reconstructPath }
