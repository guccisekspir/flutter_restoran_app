# NetYemek Projesi, Laravel based API server

## Genel mimari
Api server altyapısı Laravel kullanmaktadır. API server belirli endpointler ile isteklere yanıt verip, istekleri işleme almaktadır. Laravel altyapısı kullanmasına rağmen ihtiyaç olmayan modüller framework içerisinden çıkartılıp hafiflik amaçlanmıştır.

## Nasıl kurulur?
Sisteminizde PHP 7.3 ve üzeri sürüm, MariaDB 10.4, Composer paketleri kurulu olmalıdır. Paketler düzgün şekilde konfigüre edildikten sonra `php artisan serve` komutu ile başlatılabilir.
Veritabanı tablolarını edinebilmek için `php artisan migrate` komutunu çalıştırmanız gerekmektedir. Ayrıca `.env` dosyasını da kendi bilgilerinizle doldurmanız gerekmektedir.


## API Endpoints

### Restaurant endpoints
* `(GET) api/restaurants` (get restaurant list)
* `(POST) api/restaurants` (add a new restaurant)
  * Send post request with name key (max:40)
* `(GET) api/restaurant/{id}` (show restaurant with specified id)
* `(POST) api/restaurant/{id}` (edit restaurant with specified id)
   * Send post request with name key (max:40)
   

### Table endpoints
* `(GET) api/restaurant/{id}/tables` (get table list)
* `(POST) api/restaurant/{id}/tables` (create new table)
    * Send post request with name key (max:40)
* `(POST) api/restaurant/{id}/table/{tableId}` (edit table)
    * Send post request with name key
* `(GET) api/restaurant/{id}/table/{tableId}` (show table info)
* `(GET) api/restaurant/{id}/table/{tableId}/close` (close the table and get the money)


### Product endpoints
* `(GET) api/restaurant/{id}/products` (list all products that exists on the db)
* `(POST) api/restaurant/{id}/products` (create a new product)
    * Send post request with name (string), price (double).
* `(GET) api/restaurant/{id}/product/{productId}` (show the specified product)
* `(POST) api/restaurant/{id}/product/{productId}` (edit the specified product)
    * Send post request with name (string), price (double).


### Order endpoints
* `(GET) api/restaurant/{id}/orders` (list all orders)
* `(GET) api/restaurant/{id}/order/{orderId}` (show the specified order)
* `(POST) api/restaurant/{id}/orders/create` (create order without JSON request)
    * Send post request with table_id, product_id, amount values. That values is getting checked by validator, so send valid values.
* `(POST) api/restaurant/{id}/orders/json` (create order with JSON request)
    * Send nested orders with JSON. You must send table_id, product_id, amount in infinite values. 


## TODO List
* Kapatılan masaların ücretlerini günlük rapor verecek bir sistem haline getirmek.
* Endpointlerin aldığı ve döndürdüğü JSON responseların grafikselleştirilmesi.
* Mutfak backendinin yazılması.
* Garson prim sisteminin eklenmesi.
* Web UI yazılıp yönetim frontendi yazılması.
