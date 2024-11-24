def parse_obj(file_path):
    # Listas para armazenar os dados do OBJ
    vertices = []
    texture_coords = []
    normals = []
    faces = []

    # Abrir o arquivo OBJ
    with open(file_path, 'r') as f:
        for line in f:
            # Ignorar linhas vazias
            if line.strip() == "":
                continue

            # Processar vértices
            if line.startswith('v '):
                parts = line.split()
                vertices.append([float(parts[1]), float(parts[2]), float(parts[3])])
            
            # Processar coordenadas de textura
            elif line.startswith('vt '):
                parts = line.split()
                texture_coords.append([float(parts[1]), float(parts[2])])
            
            # Processar normais
            elif line.startswith('vn '):
                parts = line.split()
                normals.append([float(parts[1]), float(parts[2]), float(parts[3])])

            # Processar faces
            elif line.startswith('f '):
                parts = line.split()[1:]  # Ignorar o "f" inicial
                face = []
                for part in parts:
                    vertex_data = part.split('/')
                    face.append({
                        'v': int(vertex_data[0]) - 1,  # Índice do vértice (subtraído de 1 porque os índices no OBJ começam de 1)
                        't': int(vertex_data[1]) - 1,  # Índice das coordenadas de textura
                        'n': int(vertex_data[2]) - 1   # Índice da normal
                    })
                faces.append(face)

    return vertices, texture_coords, normals, faces

def generate_vertex_list(vertices, texture_coords, faces):
    # Lista para armazenar os dados de vértices com as coordenadas de textura
    vertex_list = []

    # Para cada face
    for face in faces:
        for i in range(len(face)):
            vertex_index = face[i]['v']
            tex_index = face[i]['t']

            # Posição do vértice
            x, y, z = vertices[vertex_index]
            
            # Coordenadas de textura
            u, v = texture_coords[tex_index]

            # Adicionar ao vertex_list no formato desejado
            vertex_list.append(f"{x}f, {y}f, {z}f, {u}f, {v}f,")
    
    return vertex_list

# Caminho para o arquivo .obj
file_path = 'carro.obj'

# Parse do arquivo
vertices, texture_coords, normals, faces = parse_obj(file_path)

# Gerar a lista de vértices com coordenadas de textura
vertex_list = generate_vertex_list(vertices, texture_coords, faces)

# Exibir o resultado
for vertex in vertex_list:
    print(vertex)
