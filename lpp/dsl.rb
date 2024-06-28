class Actividad
    attr_accessor :name, :precio, :tiempo, :id, :profe
    
    
   
    def initialize(id = nil, name = nil, precio = nil, tiempo = nil, profe = nil)
        @name = name
        @precio = precio
        @tiempo = tiempo
        @id = id
        @profe = profe
    end
    
    def to_s
        "Nombre: #{@name} - ID: #{@id} - Precio: #{@precio} - Tiempo: #{@tiempo} - Profe: #{@profe}"
    end
end

class Trabajo < Actividad
    attr_accessor :miembros, :jefe
    
    def initialize (id = nil, name = nil, precio = nil, tiempo = nil, profe = nil, jefe = nil)
        super(id, name, precio, tiempo, profe)
        @miembros = []
        @jefe = jefe
    end
    
    def add_miembro(miembro)
        @miembros << miembro
    end
end

class Workbook
    attr_accessor :name, :lista, :id, :datos
    
    def initialize(id, name, &block)
        @id = id
        @name = name
        @lista = []
        @datos = []
    
        if block_given?
            if block.arity == 1
                yield self
            else
                instance_eval(&block)
            end
        end
    end

    def datos(name, options = {})
        entrada = name
        entrada << "->#{options[:autor]}" if options[:autor]
        @datos << entrada
    end
    
    def lista(id, options = {})
        id = id
        name = options[:name] if options[:name]
        precio = options[:precio] if options[:precio]
        tiempo = options[:tiempo] if options[:tiempo]
        profe = options[:profe] if options[:profe]
        actividad(id, name, precio, tiempo, profe)
    end
    
    def to_s
        output = "#{@name}\nDatos:\n"
        output << "#{@datos.join(', ')}\n"
        output << "Actividades:\n"
        @lista.each do |actividad|
            output << actividad.to_s + "\n"
        end
        output
    end
    
    def actividad(id, name, precio, tiempo, profe)
        @lista << Actividad.new(id, name, precio, tiempo, profe)
    end
end

class Colegio

    attr_accessor :workbooks, :name

    def initialize(name, &block)
        @name = name
        @workbooks = []
        
        if block_given?
            if block_arity == 1
                yield self
            else 
                instance_eval(&block)
            end
        end
    end
    
    def crear_workbook(id, name, &block)
        workbook = Workbook.new(id,name, &block)
        @workbooks << workbook
        workbook
    end
    
    def encontrar_workbook(id)
        @workbooks.find do |workbook| workbook.id == id end
    end
    
    def eliminar_workbook(id)
        @workbooks.reject! do |workbook| workbook.id == id end
    end
    
    def editar_workbook(id, &block)
        workbook = encontrar_workbook(id)
        if workbook && block_given?
            workbook.instance_eval(&block)
        end
    end
    
    def to_s
        output = "Colegio:\n"
        @workbooks.each do |workbook|
            output << workbook.to_s + "\n" 
        end
        output
    end
    
            
end



a = Actividad.new(1, "PEDRO", 34, 6, "JL")
b = Actividad.new(3, "ASDF", 22, 32, "PR")

def b.prototipe
    puts "Singleton method"
end

l = Workbook.new(1, "CEIP PEDRO") do 
    datos "ingles", :autor => "pablo"
    datos "lengua", :autor => "samuel"
    
    lista 1, :name => "Guiseppe",:precio => 22, :tiempo => 44, :profe => "Fernando"
    lista 2, :name => "LAEROF"  ,:precio => 34, :tiempo => 10, :profe => "SEDDR"
end

l.actividad(2, "PEEDRO", 44, 90, "PD")
l.actividad(3, "LAGUNA", 66, 90, "PO")
puts l

b.prototipe

# Ejemplo de uso
colegio = Colegio.new("tenerife")

colegio.crear_workbook(1, "CEIP PEDRO") do
    datos "ingles", autor: "pablo"
    datos "lengua", autor: "samuel"

    lista 1, name: "Guiseppe", precio: 22, tiempo: 44, profe: "Fernando"
    lista 2, name: "LAEROF", precio: 34, tiempo: 1, profe: "SEDDR"
end

colegio.crear_workbook(2, "CEIP SAN JUAN") do
    datos "matematicas", autor: "juan"
    datos "historia", autor: "ana"

    lista 3, name: "Pedro", precio: 45, tiempo: 30, profe: "Luis"
    lista 4, name: "Ana", precio: 50, tiempo: 25, profe: "Maria"
end

colegio.editar_workbook(1) do
    actividad(3, "PEEEDRO", 44, 90, "PD")
end

puts colegio
