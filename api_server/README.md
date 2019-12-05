# NetYemek Projesi, Laravel based API server

## Genel mimari
Api server altyapısı Laravel kullanmaktadır. API server belirli endpointler ile isteklere yanıt verip, istekleri işleme almaktadır. Laravel altyapısı kullanmasına rağmen ihtiyaç olmayan modüller framework içerisinden çıkartılıp hafiflik amaçlanmıştır.

## Nasıl kurulur?
Sisteminizde PHP 7.3 ve üzeri sürüm, MariaDB 10.4, Composer paketleri kurulu olmalıdır. Paketler düzgün şekilde konfigüre edildikten sonra `php artisan serve` komutu ile başlatılabilir.

## API Endpoints

### Restaurant endpoints
* `(GET) api/restaurant` (get restaurant list)
* `(POST) api/restaurant` (add a new restaurant)
  * Send post request with name key (max:40)
* `(GET) api/restaurant/{id}` (show restaurant with specified id)
* `(POST) api/restaurant/{id}` (edit restaurant with specified id)
   * Send post request with name key (max:40)
   

### Table endpoints
* `(GET) api/restaurant/{id}/table` (get table list)
* `(POST) api/restaurant/{id}/table` (create new table)
    * Send post request with name key (max:40)
* `(POST) api/restaurant/{id}/table/{tableId}` (edit table)
    * Send post request with name key

