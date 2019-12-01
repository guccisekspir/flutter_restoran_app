import 'Siparis.dart';

class Masa {
  int _masaid;
  bool _masadurumu;
  int _tutar;
  List<Siparis> _siparis;

  Masa({int masaid, bool masadurumu, int tutar, List<Siparis> siparis}) {
    this._masaid = masaid;
    this._masadurumu = masadurumu;
    this._tutar = tutar;
    this._siparis = siparis;
  }

  int get masaid => _masaid;
  set masaid(int masaid) => _masaid = masaid;
  bool get masadurumu => _masadurumu;
  set masadurumu(bool masadurumu) => _masadurumu = masadurumu;
  int get tutar => _tutar;
  set tutar(int tutar) => _tutar = tutar;
  List<Siparis> get siparis => _siparis;
  set siparis(List<Siparis> siparis) => _siparis = siparis;

  Masa.fromJson(Map<String, dynamic> json) {
    _masaid = json['masaid'];
    _masadurumu = json['masadurumu'];
    _tutar = json['tutar'];
    if (json['siparis'] != null) {
      _siparis = new List<Siparis>();
      json['siparis'].forEach((v) {
        _siparis.add(new Siparis.fromJson(v));
      });
    }
  }

  Map<String, dynamic> toJson() {
    final Map<String, dynamic> data = new Map<String, dynamic>();
    data['masaid'] = this._masaid;
    data['masadurumu'] = this._masadurumu;
    data['tutar'] = this._tutar;
    if (this._siparis != null) {
      data['siparis'] = this._siparis.map((v) => v.toJson()).toList();
    }
    return data;
  }
}
