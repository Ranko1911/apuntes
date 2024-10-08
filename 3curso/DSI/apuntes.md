npm init --yes

----------- creamos el package.json


npm install --save-dev typedoc

**typedoc.jason se crea ahora**
**comentar las cosas**

npm run doc

------------------

npm install --save-dev mocha chai @types/mocha @types/chai ts-node

**.mocharc.json se crea ahora**

mkdir test

cd/test
 **se crea el test*

npm run test

------------------


typescript-coverage-install

	npm install --save-dev nyc coveralls

**editar el package.json "coverage: "nyc npm test"**	

hacer el repo publico

ir a la web de coveralls y activar el repo
copiar el token (segundo bloque de código)

	touch .coveralls.yml

pegar el token en .coveralls.yml

editar el package.json :
 
    "coverage": "nyc npm test && nyc report --reporter=text-lcov | coveralls && rm rf .nyc_output" 
