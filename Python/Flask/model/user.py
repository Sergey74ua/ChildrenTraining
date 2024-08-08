from datetime import datetime
from model.city import City
from app import db

class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(255), nullable=False)
    description = db.Column(db.Text, nullable=True)
    date = db.Column(db.Date, default=datetime.utcnow)
    city_id = db.Column(db.Integer, db.ForeignKey(City.id), nullable=True)
