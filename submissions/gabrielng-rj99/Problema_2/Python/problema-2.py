import networkx as nx
import sys

G = nx.Graph()
edges_count = {}
ans = 0

def count_edges(N, edges):
    global edges_count
    edges_count = {node: 0 for node in range(1, N + 1)}
    for edge in edges:
        for node in edge:
            edges_count[node] += 1

def add_ans():
    global ans, edges_count
    for node in edges_count:
        if edges_count[node] == 1:
            ans += 1

def open_edges_file(file_path):
    with open(file_path, 'r') as file:
        _N, W = map(int, file.readline().split())
        
        file_array = []

        for line in file:
            row = tuple(map(int, line.split()))
            file_array.append(row)
               
        return _N, W, file_array

def roots_leaves_from(cycle: list):
    global edges_count
    roots = []
    leaves = []

    for node in cycle:
        if not roots:
            roots = [node]
        elif edges_count[node] > edges_count[roots[0]]:
            roots = [node]
        elif edges_count[node] == edges_count[roots[0]]:
            roots.append(node)
        
        if not leaves:
            leaves = [node]
        elif edges_count[node] < edges_count[leaves[0]]:
            leaves = [node]
        elif edges_count[node] == edges_count[leaves[0]]:
            leaves.append(node)

    return roots, leaves

def is_connected(nodes: list):
    global G
    for node in nodes:
        connections = list(G.neighbors(node))
        for node_2 in connections:
            if node_2 in nodes:
                return True
    
    return False

def leaves_connected_to_not_roots(leaves, roots, cycle):
    global G
    for leaf in leaves:
        connections = list(G.neighbors(leaf))
        for node in connections:
            if node not in roots and node in cycle:
                return True
    
    return False

def erase_edge_from(cycle):
    global G
    roots, leaves = roots_leaves_from(cycle)[0], roots_leaves_from(cycle)[1] 
    if len(leaves) >= 2:
        if is_connected(leaves):
            for i in range(-1, len(leaves) - 1):
                if G.has_edge(leaves[i], leaves[i + 1]):
                    G.remove_edge(leaves[i], leaves[i + 1])
                    edges_count[leaves[i]] -= 1
                    edges_count[leaves[i + 1]] -= 1
                    break
        
        elif leaves_connected_to_not_roots(leaves, roots, cycle):
            for i in range(-1, len(cycle) - 1):
                c1 = cycle[i] in leaves
                c2 = cycle[i + 1] in leaves
                c3 = cycle[i] not in roots
                c4 = cycle[i + 1] not in roots

                check1 = all([c1, c4])
                check2 = all([c2, c3])

                if check1 or check2:
                    G.remove_edge(cycle[i], cycle[i + 1])
                    edges_count[cycle[i]] -= 1
                    edges_count[cycle[i + 1]] -= 1
                    break

        else:
            for i in range(-1, len(cycle) - 1):
                check1 = cycle[i] in leaves
                check2 = cycle[i + 1] in leaves

                if check1 or check2:
                    # print("checkpoint 1.3.1")
                    G.remove_edge(cycle[i], cycle[i + 1])
                    edges_count[cycle[i]] -= 1
                    edges_count[cycle[i + 1]] -= 1
                    break

    else:
        if leaves_connected_to_not_roots(leaves, roots, cycle):
            for i in range(-1, len(cycle) - 1):
                c1 = cycle[i] in leaves
                c2 = cycle[i + 1] in leaves
                c3 = cycle[i] not in roots
                c4 = cycle[i + 1] not in roots

                check1 = c1 or c2
                check2 = c3 or c4

                if check1 and check2:
                    G.remove_edge(cycle[i], cycle[i + 1])
                    edges_count[cycle[i]] -= 1
                    edges_count[cycle[i + 1]] -= 1
                    break

        else:
            for i in range(-1, len(cycle) - 1):
                check1 = cycle[i] in leaves
                check2 = cycle[i + 1] in leaves

                if check1 or check2:
                    G.remove_edge(cycle[i], cycle[i + 1])
                    edges_count[cycle[i]] -= 1
                    edges_count[cycle[i + 1]] -= 1
                    break

def find_cycle_starting_from(start_node):
    global G
    try:
        cycle_edges = nx.find_cycle(G, source=start_node)
        cycle_nodes = [u for u, _ in cycle_edges]
        return cycle_nodes
    except nx.NetworkXNoCycle:
        return None

def break_all_cycles():
    global G
    start_node = max(edges_count, key=edges_count.get)
    while nx.cycle_basis(G):
        cycle = find_cycle_starting_from(start_node)
        erase_edge_from(cycle)

def main(file_path):
    global G, ans
    N, _W, file_array = open_edges_file(file_path)
    G.add_edges_from(file_array)
    count_edges(N, file_array)
    break_all_cycles()
    add_ans()

    return ans

if __name__ == '__main__':
    file_path = sys.argv[1]
    print(f"{main(file_path):>10}")