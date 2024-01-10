CREATE DATABASE ticketbooking;

CREATE TABLE users (
    id bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name varchar(255) NOT NULL,
    username varchar(255) NOT NULL,
    password varchar(255) NOT NULL,
    role_id bigint(20) NOT NULL
);

CREATE TABLE cinemas (
    id bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name varchar(255) NOT NULL,
    address varchar(255) NOT NULL
);

CREATE TABLE rooms (
    id bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name varchar(255) NOT NULL,
    quantity_seats bigint(20) NOT NULL,
    cinema_id bigint(20) UNSIGNED NOT NULL,
    status bigint(20) NOT NULL,
    FOREIGN KEY (cinema_id) REFERENCES cinemas(id)
);

CREATE TABLE seats (
    id bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    room_id bigint(20) UNSIGNED NOT NULL,
    status bigint(20) NOT NULL,
    FOREIGN KEY (room_id) REFERENCES rooms(id)
);

CREATE TABLE categories (
    id bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name varchar(255) NOT NULL
);

CREATE TABLE films (
    id bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    title varchar(255) NOT NULL,
    category_id bigint(20) UNSIGNED NOT NULL,
    show_time bigint(20) UNSIGNED NOT NULL,
    FOREIGN KEY (category_id) REFERENCES categories(id)
);

CREATE TABLE premiered_time (
    id bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    start_time varchar(255) NOT NULL,
    finish_time varchar(255) NOT NULL
);

CREATE TABLE premiered_time_film (
    id bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    film_id bigint(20) UNSIGNED NOT NULL,
    premiered_time_id bigint(20) UNSIGNED NOT NULL,
    cinema_id bigint(20) UNSIGNED NOT NULL,
    date varchar(255) NOT NULL,
    FOREIGN KEY (film_id) REFERENCES films(id),
    FOREIGN KEY (premiered_time_id) REFERENCES premiered_time(id),
    FOREIGN KEY (cinema_id) REFERENCES cinemas(id)
);

CREATE TABLE tickets (
    id bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT PRIMARY KEY,
    user_id bigint(20) UNSIGNED NOT NULL,
    premiered_time_film_id bigint(20) UNSIGNED NOT NULL,
    seat_id bigint(20) UNSIGNED NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (premiered_time_film_id) REFERENCES premiered_time_film(id),
    FOREIGN KEY (seat_id) REFERENCES seats(id)
);
