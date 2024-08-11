from flask import render_template, request, redirect
from app import app, db
from model.user import User
from model.city import City

@app.route("/")
def home():
    return 'Hello world!<br><a href="index">Главная</a>'

@app.route("/index")
def index():
    return render_template('index.html')

@app.route("/about")
def about():
    return render_template('about.html')

@app.route("/create", methods=['POST', 'GET'])
def create():
    if request.method == 'POST':
        name = request.form['name']
        description = request.form['description']
        city = request.form['city']
        user = User(name=name, description=description, city_id=city)
        try:
            db.session.add(user)
            db.session.commit()
            return redirect('/user/'+ str(user.id))
        except:
            return 'Возникла ошибка при записи в БД'
    else:
        date = {
            'title': 'Добавление пользователя',
            'city': City.query.all()
        }
        return render_template('create.html', date=date)

@app.route("/users")
def users():
    users = User.query.all()
    return render_template('users.html', data=users)

@app.route("/user/<int:id>")
def user(id):
    user = User.query.get(id)
    user.city_id = City.query.get(user.city_id).name
    return render_template('user.html', data=user)

@app.route("/user/<int:id>/update", methods=['GET', 'POST'])
def userUpdate(id):
    user = User.query.get(id)
    if request.method == 'POST':
        user.name = request.form['name']
        user.description = request.form['description']
        user.city_id = request.form['city']
        try:
            db.session.commit()
            return redirect('/user/'+ str(user.id))
        except:
            return 'Возникла ошибка при обновлении записи БД'
    else:
        data = {
            'title': 'Редактирование пользователя',
            'user': user,
            'city': City.query.all()
        }
        return render_template('update.html', data=data)

@app.route("/user/<int:id>/delete")
def userDelete(id):
    user = User.query.get_or_404(id)
    try:
        db.session.delete(user)
        db.session.commit()
        return redirect('/users')
    except:
        return 'Возникла ошибка при удалении записи из БД'
