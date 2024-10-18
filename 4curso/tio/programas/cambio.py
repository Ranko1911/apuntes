def eliminar_lineas_especificas(input_file, output_file):
    # Usamos 'ISO-8859-1' para evitar problemas de decodificación
    with open(input_file, mode='r', encoding='ISO-8859-1') as infile:
        lines = infile.readlines()

    with open(output_file, mode='w', encoding='ISO-8859-1') as outfile:
        for line in lines:
            # Eliminar el salto de línea al final para facilitar la comparación
            line = line.strip()

            # Verifica si la línea comienza con 'C', termina en ';', en '?', o en 'lost'
            if not line.startswith('C') and not line.endswith(';') and not line.endswith('?') and not line.endswith('lost'):
                outfile.write(line + '\n')

    print(f"Las líneas filtradas se han guardado en {output_file}")


# Ejemplo de uso
input_file = 'OnlineRetail_17.csv'
output_file = 'NewOnlineRetail_17.csv'
eliminar_lineas_especificas(input_file, output_file)
