from os import sep
from MySQLdb import connect
from flask import Flask, render_template, request, session, redirect, url_for, session
from flask_mysqldb import MySQL, MySQLdb
# import bcrypt
import json
import random
from datetime import date

import pandas as pd
import numpy as np

with open('config.json','r') as c:
    params = json.load(c)["params"]

local_server = True
app = Flask(__name__)

app.config['MYSQL_HOST'] = params['MYSQL_HOST']
app.config['MYSQL_USER'] = params['MYSQL_USER']
app.config['MYSQL_PASSWORD'] = params['MYSQL_PASSWORD']
app.config['MYSQL_DB'] = params['MYSQL_DB']
app.config['MYSQL_CURSORCLASS'] = params['MYSQL_CURSORCLASS']

app.secret_key = 'super-secret-key'
mysql = MySQL(app)

@app.route("/")
def home():
    cur = mysql.connection.cursor()
    cur.execute("CREATE TABLE IF NOT EXISTS Customer (cus_id INTEGER PRIMARY KEY AUTO_INCREMENT, cus_name VARCHAR(20) NOT NULL, cus_phone VARCHAR(13), cus_email VARCHAR(30) UNIQUE, cus_pass VARCHAR(20) NOT NULL, premium VARCHAR(10))")
    cur.execute("CREATE TABLE IF NOT EXISTS Address (address_id INTEGER PRIMARY KEY AUTO_INCREMENT, cus_id INTEGER, address VARCHAR(50), city VARCHAR(10), zipcode INTEGER(5), FOREIGN KEY (cus_id) REFERENCES Customer(cus_id))")
    cur.execute("CREATE TABLE IF NOT EXISTS Category(category_id INTEGER PRIMARY KEY AUTO_INCREMENT, category_name VARCHAR(20) NOT NULL, toppings VARCHAR(30), topping_price INTEGER)")
    cur.execute("CREATE TABLE IF NOT EXISTS Restaurant(res_id INTEGER PRIMARY KEY AUTO_INCREMENT, res_name VARCHAR(20) NOT NULL, category_id INTEGER, FOREIGN KEY(category_id) REFERENCES Category(category_id))")
    cur.execute("CREATE TABLE IF NOT EXISTS Food(food_id INTEGER PRIMARY KEY AUTO_INCREMENT, food_name VARCHAR(20), food_price INTEGER, category_id INTEGER, res_id INTEGER, image_url varchar(20) , FOREIGN KEY(category_id) REFERENCES Category(category_id), FOREIGN KEY(res_id) REFERENCES Restaurant(res_id))")
    cur.execute("CREATE TABLE IF NOT EXISTS Rider(rider_id INTEGER PRIMARY KEY AUTO_INCREMENT , rider_name VARCHAR(20), rider_phone VARCHAR(20), vehicle_num_plate VARCHAR(20), rider_cnic VARCHAR(20))")
    cur.execute("CREATE TABLE IF NOT EXISTS Orderr(order_id INTEGER PRIMARY KEY  AUTO_INCREMENT, cus_id INTEGER, rider_id INTEGER, order_date TIMESTAMP NOT NULL, discount FLOAT DEFAULT 0.0, total_price FLOAT, discounted_price FLOAT, FOREIGN KEY (cus_id) REFERENCES Customer(cus_id), FOREIGN KEY (rider_id) REFERENCES Rider(rider_id))")
    cur.execute("CREATE TABLE IF NOT EXISTS SubOrder(sub_order_id INTEGER PRIMARY KEY AUTO_INCREMENT, res_id INTEGER, order_id INTEGER, category_id INTEGER, food_id INTEGER, food_price INTEGER, FOREIGN KEY (res_id) REFERENCES Restaurant(res_id), FOREIGN KEY (order_id) REFERENCES Orderr(order_id), FOREIGN KEY (category_id) REFERENCES Category(category_id), FOREIGN KEY (food_id) REFERENCES Food(food_id))")
    cur.execute("CREATE TABLE IF NOT EXISTS CreditCardInfo(card_num VARCHAR(20), cus_id INTEGER, card_valid DATE, card_expire DATE, cvc INTEGER(3), FOREIGN KEY (cus_id) REFERENCES Customer(cus_id), PRIMARY KEY (card_num, cus_id))")
    cur.execute("CREATE TABLE IF NOT EXISTS Billing(bill_id INTEGER PRIMARY KEY AUTO_INCREMENT , cus_id INTEGER, order_id INTEGER, rider_id INTEGER, payment_method VARCHAR(20), FOREIGN KEY (cus_id) REFERENCES Customer(cus_id), FOREIGN KEY (order_id) REFERENCES Orderr(order_id), FOREIGN KEY (rider_id) REFERENCES Rider(rider_id))")
    cur.execute("CREATE TABLE IF NOT EXISTS Reviews(rev_id INTEGER PRIMARY KEY AUTO_INCREMENT, cus_id INTEGER, order_id INTEGER, review VARCHAR(200), review_date TIMESTAMP DEFAULT NOW(), FOREIGN KEY (cus_id) REFERENCES Customer(cus_id), FOREIGN KEY (order_id) REFERENCES Orderr(order_id))")
    cur.execute("CREATE TABLE IF NOT EXISTS Admin(admin_id INTEGER PRIMARY KEY AUTO_INCREMENT, rev_id INTEGER, res_id INTEGER, order_id INTEGER, rider_id INTEGER, bill_id INTEGER, FOREIGN KEY (rider_id) REFERENCES Rider(rider_id), FOREIGN KEY (res_id) REFERENCES Restaurant(res_id), FOREIGN KEY (order_id) REFERENCES Orderr(order_id), FOREIGN KEY (bill_id) REFERENCES Billing(bill_id))")
    cur.execute("CREATE TABLE IF NOT EXISTS Toppings(topping_id INTEGER PRIMARY KEY AUTO_INCREMENT, topping_name VARCHAR(20), topping_price INTEGER, category_id INTEGER, FOREIGN KEY(category_id) REFERENCES Category(category_id))")
    cur.close()
    return render_template('index.html', params = params)



order_static = False # for /cart function but will set here
orderid = 0
@app.route("/order", methods=['GET', 'POST'])
def order():
    cur = mysql.connection.cursor()
    cur.execute("SELECT category_name, image_url FROM Category")
    cat  = cur.fetchall()
    cur.close()
    return render_template('order.html',params=params,cat=cat)


@app.route("/signup",methods=['GET', 'POST'])
def signup():
    if(request.method=='POST'):
        name = request.form.get('Name')
        email = request.form.get('Email')
        contact = request.form.get('Contact')
        password = request.form.get('Password')
        membership = request.form.get('membership')
        cur = mysql.connection.cursor()

        cur.execute("select * from customer where cus_email = %s",([email],))
        record = cur.fetchone()
        if(record != None):
            return render_template('signup.html', params = params)

        cur.execute("INSERT INTO customer (cus_name, cus_phone, cus_email, cus_pass, premium) VALUES(%s,%s,%s,%s,%s)",([name],[contact],[email],[password],[membership],))
        mysql.connection.commit()
        cur.close()
        return render_template('login.html', params = params)
    return render_template('signup.html', params = params)

@app.route("/Restaurants",methods=['GET', 'POST'])
def Restaurants():
    if request.method == 'POST':
        categor = request.form.get("category")
        curl = mysql.connection.cursor()
        curl.execute("select res_name, url_image from restaurant where category_id in (select category_id from category where category_name = %s)",([categor],))
        user = curl.fetchall()
        curl.close()
        return render_template('Restaurants.html',params=params,user=user)

@app.route("/menu",methods=['GET', 'POST'])
def menu():
    if request.method == 'POST':
        res= request.form.get('res_name')
        curl = mysql.connection.cursor()

        curl.execute("select f.food_id, f.food_name, f.food_price, f.category_id, f.image_url, c.category_name from food f, category c, restaurant r where f.category_id = c.category_id and f.res_id = r.res_id and r.res_name = %s",([res],))
        menu_items = curl.fetchall()

        curl.execute("select f.food_id, f.food_name, f.food_price, f.category_id, f.image_url, c.category_name from food f, category c, restaurant r where f.category_id = c.category_id and f.res_id = r.res_id and r.res_name = %s",([res],))
        cat_name = curl.fetchone()
        curl.close()
        return render_template('menu.html',params=params, menu_items = menu_items, cat_name = cat_name)
    return render_template('login.html',params=params)

@app.route("/card", methods=['GET', 'POST'])
def card():
    if request.method == 'POST':
        full_name = request.form.get('Full_Name')
        card_num = request.form.get('CardNum')
        exp = request.form.get('Expiration')
        cvv = request.form.get('cvc')

        cur = mysql.connection.cursor()
        cur.execute("select card_num from creditcardinfo where cus_id = %s",([session['id']],))
        cards = cur.fetchone()
        if(cards != None):
            cur.execute("delete from creditcardinfo where card_num = %s and cus_id = %s",([card_num],[session['id']],))

        cur.execute("insert into creditcardinfo (card_num,cus_id, card_expire, cvc, card_holder_name) VALUES(%s,%s,%s,%s,%s)",([card_num],[session['id']],[exp],[cvv],[full_name],))
        mysql.connection.commit()
        cur.close()
        return redirect(url_for('summary'))
    return render_template('card.html',params=params)

@app.route("/cart", methods=['GET', 'POST'])
def cart():
    if request.method == 'POST':
        if('loggedin' not in session):
            return render_template('login.html',params = params)
        if(session['loggedin']== False):
            return render_template('login.html',params = params)

        id = session['id']
        cur = mysql.connection.cursor()
        global order_static
        orderid = 0
        f = open("ordernum.txt", "r")
        orderid = int(f.read())
        f.close()

        if (order_static == False):
            orderid = orderid+1
            f = open("ordernum.txt", "w")
            f.write(str(orderid))
            f.close()

            cur.execute("select premium from customer where cus_id = %s", ([id],))
            premium = cur.fetchone()
            cur.execute("INSERT INTO orderr (order_id, cus_id, discount) VALUES(%s,%s,%s)", ([orderid],[id],[premium['premium']],))
            mysql.connection.commit()
            order_static = True

        food_id = request.form.get("food_id")
        cur.execute("SELECT * FROM food WHERE food_id = %s", ([food_id]))
        item  = cur.fetchone()
        res_id = item['res_id']
        category_id = item['category_id']
        food_id = item['food_id']
        food_price = item['food_price']
        o_id = orderid
        cur.execute("INSERT INTO suborder (res_id, order_id, category_id, food_id, food_price) VALUES(%s,%s,%s,%s,%s)", ([res_id],[o_id],[category_id],[food_id],[food_price]))
        mysql.connection.commit()

        cur.execute("SELECT category_name, image_url FROM Category")
        cat  = cur.fetchall()
        cur.close()
        return render_template('order.html',params=params,cat=cat)
    return render_template('menu.html',params=params)


@app.route("/showcart", methods=['GET', 'POST'])
def showcart():
    cur = mysql.connection.cursor()

    checkout = 0
    cur.execute("select order_id, discount from orderr where cus_id = %s and checkout = %s",([session['id']],[checkout],))
    o_id = cur.fetchone()

    cur.execute("SELECT f.food_id, f.food_name, f.food_price, s.sub_order_id, r.res_name from food f, restaurant r, suborder s where r.res_id = f.res_id and f.food_id = s.food_id and s.order_id = %s", (o_id['order_id'],))
    item_records = cur.fetchall()

    total_price = 0
    for item in item_records:
        total_price = total_price + item['food_price']

    discount = o_id['discount']
    discounted_price = total_price - (total_price*discount/100)
    cur.execute("UPDATE orderr set total_price = %s, discounted_price = %s where order_id = (select order_id from orderr where cus_id = %s and checkout = %s)",([total_price],[discounted_price],[session['id']],[checkout],))
    mysql.connection.commit()

    cur.execute("select premium from customer where cus_id = %s",([session['id']],))
    promo = cur.fetchone()
    cur.close()

    return render_template('cart.html', params = params, item_records = item_records, total_price = total_price, promo = promo, discounted_price = discounted_price)

@app.route("/checkout", methods=['GET', 'POST'])
def checkout():
    if(request.method=='POST'):
        f_name = request.form.get('First_name')
        l_name = request.form.get('Last_name')
        contact = request.form.get('Contact')
        address = request.form.get('Address')
        city = request.form.get('city')
        postcode = request.form.get('PostCode')
        paymentMethod = request.form.get('paymentMethod')

        cur = mysql.connection.cursor()
        cur.execute("select address_id from address where cus_id = %s", ([session['id']],))
        addr = cur.fetchall()
        if(addr!=None):
            cur.execute("delete from address where cus_id = %s",([session['id']],))
        cur.execute("insert into address (cus_id, address, city, zipcode) values (%s,%s,%s,%s)",([session['id']],[address],[city],[postcode],))
        mysql.connection.commit()
        checkout = 0
        cur.execute("select order_id from orderr where cus_id = %s and checkout = %s", ([session['id']],[checkout],))
        ord_id = cur.fetchone()
        cur.execute("select rider_id from rider")
        rider = cur.fetchall()
        rider_list = []
        for r in rider:
            rider_list.append(r['rider_id'])
        rider_id = random.choice(rider_list)

        cur.execute("update orderr set rider_id = %s where order_id = %s and cus_id = %s", ([rider_id],[ord_id['order_id']], [session['id']],))
        cur.execute("select * from Billing where order_id = %s and cus_id = %s", ([ord_id['order_id']], [session['id']],))
        records = cur.fetchall()
        if(records != None):
            cur.execute("delete from Billing where order_id = %s and cus_id = %s", ([ord_id['order_id']], [session['id']],))

        cur.execute("insert into Billing (cus_id, order_id, rider_id, payment_method, Address, PostCode) VALUES(%s,%s,%s,%s,%s,%s)",([session['id']],[ord_id['order_id']],[rider_id],[paymentMethod],[address],[postcode],))
        mysql.connection.commit()

        if ('future-schedule' not in session):
            session['future-schedule'] = 0
        cur.execute("update orderr set future = %s where cus_id = %s and order_id = %s",([session['future-schedule']],[session['id']],[ord_id['order_id']],))
        mysql.connection.commit()


        checkout = 0
        cur.execute("select order_id, discount, total_price from orderr where cus_id = %s and checkout = %s",([session['id']],[checkout],))
        o_id = cur.fetchone()

        cur.execute("SELECT s.sub_order_id from food f, restaurant r, suborder s where r.res_id = f.res_id and f.food_id = s.food_id and s.order_id = %s", (o_id['order_id'],))
        item_records = cur.fetchall()

        total_price = o_id['total_price']

        for item in item_records:
            cur.execute("select topping_id from suborder where sub_order_id = %s", ([item['sub_order_id']],))
            top_id = cur.fetchone()
            if(top_id['topping_id'] != None):
                cur.execute("select topping_price from toppings where topping_id = %s",([top_id['topping_id']],))
                check = cur.fetchone()
                total_price = total_price + check['topping_price']

        discount = o_id['discount']
        discounted_price = total_price - (total_price*discount/100)

        cur.execute("UPDATE orderr set total_price = %s, discounted_price = %s where order_id = (select order_id from orderr where cus_id = %s and checkout = %s)",([total_price],[discounted_price],[session['id']],[checkout],))
        mysql.connection.commit()

        cur.close()
        if(paymentMethod == 'Cash on Delivery'):
            return redirect(url_for('summary'))
        else:
            return render_template('card.html',params=params)
    else:
        return render_template('checkout.html',params=params)

@app.route("/login",methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        email = request.form.get('Email')
        userpass = request.form.get('Password')
        curl = mysql.connection.cursor(MySQLdb.cursors.DictCursor)
        curl.execute("SELECT * FROM Customer WHERE cus_email=%s",([email],))
        user = curl.fetchone()
        curl.close()

        if(len(user)>0):
            if(userpass == user['cus_pass']):
                myresult = curl.fetchall()
                # yahan se edit karraha hun
                session['loggedin'] = True
                session['id'] = user['cus_id']
                session['username'] = user['cus_name']
                session['future-schedule'] = 0
                global order_static
                order_static = False

                cur = mysql.connection.cursor()
                cur.execute("SELECT * FROM orderr where cus_id = %s", ([session['id']],))
                item = cur.fetchall()

                order_list = []
                for check in item:
                    if (check['checkout'] == '0'):
                        order_list.append(check['order_id'])

                for id in order_list:
                    cur.execute("DELETE FROM suborder where order_id = %s",([id],))
                    mysql.connection.commit()
                    cur.execute("DELETE FROM orderr where order_id = %s",([id],))
                    mysql.connection.commit()
                cur.close()
                return render_template("index.html",params=params)
            else:
                return render_template("login.html", params=params)

    return render_template("login.html", params=params)

@app.route("/Rider", methods=['GET', 'POST'])
def Rider():
    if request.method =='POST':
        name = request.form.get('Name')
        contact = request.form.get('Contact')
        CNIC = request.form.get('CNIC')
        BRN = request.form.get('BRN')
        License = request.form.get('License')

        cur = mysql.connection.cursor()
        cur.execute("insert into rider (rider_name,rider_phone,vehicle_num_plate,rider_cnic,driving_license) values (%s,%s,%s,%s,%s)", ([name],[contact],[CNIC],[BRN],[License],))
        mysql.connection.commit()
        cur.close()
        return render_template("index.html",params = params)
    return render_template("RiderRegister.html",params = params)

@app.route("/logout")
def logout():
    session.pop('loggedin', None)
    session.pop('id', None)
    session.pop('username', None)
    global order_static
    order_static = False
    return render_template("index.html",params = params)

@app.route("/contactus")
def contactus():
    return render_template("contactus.html", params = params)

@app.route("/summary")
def summary():
    cur = mysql.connection.cursor()
    checkout = 0
    cur.execute("select cus_id, order_id, total_price, discounted_price from orderr where cus_id = %s and checkout = %s", ([session['id']],[checkout],))
    rec = cur.fetchone()
    if(rec == None):
        return render_template('index.html',params = params)
    order_id = rec['order_id']
    checkout = 1
    cur.execute("update orderr set checkout = %s where cus_id = %s and order_id = %s", ([checkout],[session['id']],[order_id],))
    mysql.connection.commit()
    cur.execute("select c.cus_name, c.cus_phone, a.address, b.rider_id, r.rider_name, r.vehicle_num_plate, r.rider_phone, b.payment_method from rider r, customer c, address a, billing b where c.cus_id = a.cus_id and b.cus_id = c.cus_id and r.rider_id = b.rider_id and b.order_id = %s", ([order_id],))
    recor = cur.fetchone()
    cur.close()
    return render_template("summary.html", params = params, rec = rec, recor = recor)

@app.route("/tracking", methods=['GET', 'POST'] )
def tracking():
    cur = mysql.connection.cursor()
    if request.method == 'POST':
        order_id = request.form.get('order_number')
    else:
        order_id = session['order_num']
    cus_id = session['id']
    cur.execute("select cus_id, order_id, total_price, discounted_price from orderr where cus_id = %s and order_id = %s", ([session['id']],[order_id],))
    rec = cur.fetchone()
    if(rec == None):
        return render_template('index.html',params = params)
    
    cur.execute("select c.cus_name, c.cus_phone, a.address, b.rider_id, r.rider_name, r.vehicle_num_plate, r.rider_phone, b.payment_method from rider r, customer c, address a, billing b where c.cus_id = a.cus_id and b.cus_id = c.cus_id and r.rider_id = b.rider_id and b.order_id = %s", ([order_id],))
    recor = cur.fetchone()
    cur.close()

    future = ''
    if ('future-schedule' not in session):
        future = 'no'
    elif (session['future-schedule'] == 1):
        future = 'yes'
    return render_template("tracking.html", params = params, rec = rec, recor = recor, future = future)


@app.route("/adminLogin", methods=['GET', 'POST'] )
def adminLogin():
    if request.method=='POST':
        email = request.form.get('email')
        password = request.form.get('password')

        if(email == 'admin@gmail.com' and password == 'admin'):
            return render_template("adminFunctions.html", params = params)
        else:
            return render_template("admin.html", params = params)
    else:
        return render_template("admin.html", params = params)

@app.route("/adminFunctions")
def adminFunctions():
    return render_template("adminFunctions.html", params = params)

@app.route("/RestaurantRegister", methods=['GET', 'POST'] )
def RestaurantRegister():
    if request.method == 'POST':
        name = request.form.get("name")
        name = name.upper()
        contact = request.form.get("contact")
        address = request.form.get("address")
        cat_id = request.form.get("Category")
        cur = mysql.connection.cursor()
        cur.execute("INSERT INTO restaurant (res_name, category_id) values (%s,%s)",([name],[cat_id],))
        mysql.connection.commit()
        cur.close()
        return render_template("login.html", params = params)
    else:
        cur = mysql.connection.cursor()
        cur.execute("SELECT * FROM CATEGORY")
        item = cur.fetchall()
        cur.close()
        return render_template("RestaurantRegister.html", params = params, item = item)

@app.route("/pretracking", methods=['GET', 'POST'] )
def pretracking():
    if request.method == 'POST':
        order_number = request.form.get("order_number")
        cur = mysql.connection.cursor()
        cur.execute("select * from orderr where order_id = %s",([order_number],))
        cur.close()
        session['order_num'] = order_number

        text = ''
        return redirect(url_for('tracking'))
    else:
        if('future-schedule' not in session or session['future-schedule'] == 0):
            text = ''
            return render_template("pretracking.html", params = params, text = text)
        elif(session['future-schedule']==1):
            text = 'can not track future order.'
            return render_template("pretracking.html", params = params, text = text)

@app.route("/premium", methods=['GET', 'POST'] )
def premium():
    if request.method == 'POST':
        name = request.form.get("name")
        contact = request.form.get("contact")
        address = request.form.get("request")
        premium = request.form.get("membership")

        cur = mysql.connection.cursor()
        cur.execute("update customer set premium = %s where cus_id = %s",([premium],[session['id']],))
        mysql.connection.commit()
        cur.close()
        return render_template("index.html", params = params)
    else:
        if('id' in session):
            cus_id = session['id']
            cur = mysql.connection.cursor()
            cur.execute("select * from customer where cus_id = %s", ([cus_id],))
            customer = cur.fetchone()
            return render_template("premium.html", params = params, customer = customer)
        return render_template("login.html", params = params)


@app.route("/futureschedule", methods=['GET', 'POST'] )
def futureschedule():
    if request.method == 'POST':
        date = request.form.get("trip-start")
        session['future-schedule'] = 1
        return redirect(url_for('order'))
    else:
        return render_template("futureschedule.html", params = params)

@app.route("/customization", methods=['GET', 'POST'] )
def customization():
    if request.method == 'POST':
        customize = request.form.get("customize")
        cur = mysql.connection.cursor()

        checkout=0
        cur.execute("select order_id from orderr where cus_id = %s and checkout = %s",([session['id']],[checkout],))
        o_id = cur.fetchone()

        cur.execute("update suborder set topping_id = %s where order_id = %s and category_id = (select category_id from toppings where topping_id = %s)",([customize],[o_id['order_id']],[customize],))
        mysql.connection.commit()
        return render_template("checkout.html", params = params)
    else:
        cur = mysql.connection.cursor()
        checkout = 0
        cur.execute("select order_id from orderr where cus_id = %s and checkout = %s",([session['id']],[checkout],))
        o_id = cur.fetchone()

        cur.execute("SELECT f.food_id, f.food_name, s.category_id, r.res_name from food f, restaurant r, suborder s where r.res_id = f.res_id and f.food_id = s.food_id and s.order_id = %s", (o_id['order_id'],))
        item_records = cur.fetchall()

        cur.execute("select * from toppings where category_id in (SELECT s.category_id from food f, restaurant r, suborder s where r.res_id = f.res_id and f.food_id = s.food_id and s.order_id = %s)", (o_id['order_id'],))
        toppings = cur.fetchall()

        topping_name = []
        topping_price = []
        topping_id = []

        for top in toppings:
            topping_name.append(top['topping_name'])
            topping_price.append(top['topping_price'])
            topping_id.append(top['topping_id'])
            
        return render_template("customization.html", params = params, item_records = item_records, topping_name = topping_name, topping_price = topping_price, topping_id = topping_id)


@app.route("/review", methods=['GET', 'POST'] )
def review():
    if request.method == 'POST':
        email = request.form.get("email")
        order_id = request.form.get("order_id")
        review = request.form.get("review")
        rev_date = date.today()

        cur = mysql.connection.cursor()
        cur.execute("select cus_id from customer where cus_email = %s", ([email],))
        cus_id = cur.fetchone()

        cur.execute("select * from orderr where order_id = %s",([order_id]))
        o_id = cur.fetchone()

        if(cus_id!= None and o_id !=None):
            cur.execute("insert into reviews(cus_id, order_id, review, review_date) values (%s,%s,%s,%s)",([cus_id['cus_id']],[order_id],[review],[rev_date],))
            mysql.connection.commit()
            cur.close()
            return render_template("index.html", params = params)
    return render_template("review.html", params = params)

@app.route("/reviewmanagement", methods=['GET', 'POST'] )
def reviewmanagement():
    cur = mysql.connection.cursor()
    cur.execute("Select c.cus_name, r.review from reviews r, customer c where c.cus_id = r.cus_id")
    rev = cur.fetchall()
    cur.close()
    return render_template("reviewmanagement.html", params = params, rev = rev)

app.run(debug=True)