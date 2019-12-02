import 'dart:convert';
import 'dart:async';

import 'package:flare_flutter/flare_actor.dart';
import 'package:flutter/material.dart';
import 'package:restappi/main.dart';
import 'package:restappi/models/Masa.dart';

class TablePages extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    // TODO: implement createState
    return tablePageState();
  }
}

// ignore: camel_case_types
class tablePageState extends State {
  List<Masa> cekilenMasalar;

  @override
  void initState() {
    // TODO: implement initState
    super.initState();
    cekilenMasalar=[];
    debugPrint("İnit state çalıştı");

  }

  @override
  Widget build(BuildContext context) {

    // TODO: implement build
    return Container(
      decoration: BoxDecoration(
        gradient: LinearGradient(
            colors: [renkGarsonYesil, Color.fromARGB(255, 74, 0, 224)]),
      ),
      child: FutureBuilder(
        future: veriHazirla(),
        builder: (context, sonuc) {
          if (sonuc.hasData) {
            cekilenMasalar = sonuc.data;
            return GridView.builder(
              gridDelegate: SliverGridDelegateWithFixedCrossAxisCount(crossAxisCount: 2),

              itemBuilder: (context, index) {
                return Container(
                  padding: EdgeInsets.all(10.0),
                  margin: EdgeInsets.all(10.0),
                  decoration: BoxDecoration(
                    color: cekilenMasalar[index].masadurumu==true?Colors.green:Colors.red,
                    borderRadius: BorderRadius.circular(40)
                    
                  ),
                  
                  child: Column(
                    mainAxisAlignment: MainAxisAlignment.center,
                    
                    children: <Widget>[
                      Text("Masa"+cekilenMasalar[index].masaid.toString()),
                      Text(cekilenMasalar[index].tutar.toString()+"TL")
                    ],
                  ),
                );
              },
              itemCount: cekilenMasalar.length,
            );
          } else
            return Center(child: CircularProgressIndicator());
        },
      ),
    );
  }

  Future<List<Masa>> veriHazirla() async {
    var gelenJson = await DefaultAssetBundle.of(context)
        .loadString("assets/localDeneme.json");
    debugPrint(gelenJson);

    List<Masa> masalar = (json.decode(gelenJson) as List)
        .map((mapYapisi) => Masa.fromJson(mapYapisi))
        .toList();
    return masalar;
  }
}
