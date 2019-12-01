class Siparis {
  String _urunadi;
  int _adedi;
  String _not;

  Siparis({String urunadi, int adedi, String not}) {
    this._urunadi = urunadi;
    this._adedi = adedi;
    this._not = not;
  }

  String get urunadi => _urunadi;
  set urunadi(String urunadi) => _urunadi = urunadi;
  int get adedi => _adedi;
  set adedi(int adedi) => _adedi = adedi;
  String get not => _not;
  set not(String not) => _not = not;

  Siparis.fromJson(Map<String, dynamic> json) {
    _urunadi = json['urunadi'];
    _adedi = json['adedi'];
    _not = json['not'];
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = new Map<String, dynamic>();
    data['urunadi'] = this._urunadi;
    data['adedi'] = this._adedi;
    data['not'] = this._not;
    return data;
  }
}