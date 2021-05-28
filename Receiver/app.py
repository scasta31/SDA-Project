from bottle import route, run, template

@route('/hello/<name>')
def index(name):
    return template('<b>Hola {{name}}</b>!', name=name)

run(host='localhost', port=8000)