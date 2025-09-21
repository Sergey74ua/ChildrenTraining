#!/usr/bin/env python3

from flask import Flask
import sys

app = Flask(__name__)

@app.route("/")
def index():
    text = "<h1>Hello world!</h1>"
    text += str(sys.version)
    return(text)

app.run(debug=True)
