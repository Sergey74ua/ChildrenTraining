from flask import Flask, render_template, request, redirect
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///sqlite.db'
db = SQLAlchemy(app)

class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(255), nullable=False)
    description = db.Column(db.Text, nullable=True)

@app.route("/")
def home():
    return 'Hello world!<br><a href="index">Главная</a>'

@app.route("/index")
def index():
    return render_template('index.html')

@app.route("/about")
def about():
    return render_template('about.html')

@app.route("/users")
def users():
    users = User.query.all()
    return render_template('users.html', data=users)

@app.route("/create", methods=['POST', 'GET'])
def create():
    if request.method == 'POST':
        name = request.form['name']
        description = request.form['description']
        user = User(name=name, description=description)
        try:
            db.session.add(user)
            db.session.commit()
            return redirect('index')
        except:
            return 'Возникла ошибка при записи в БД'
    else:
        return render_template('create.html')

@app.route("/user/<int:id>")
def user(id):
    string = "Пользователь № " + str(id)
    return string

if __name__ == '__main__':
    app.run(debug=True)
