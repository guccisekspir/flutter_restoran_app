import 'dart:convert';
import 'dart:async';

import 'package:flare_flutter/flare_actor.dart';
import 'package:flutter/material.dart';
import 'package:restappi/main.dart';
import 'package:restappi/models/Masa.dart';
import 'package:restappi/models/Siparis.dart';

TextStyle masaText = TextStyle(
  color: Colors.white,
  fontSize: 15,
  fontFamily: 'Raleway',
);

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
    cekilenMasalar = [];
    debugPrint("İnit state çalıştı");
  }

  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Container(
      decoration: BoxDecoration(
        gradient: LinearGradient(
            begin: Alignment.bottomLeft,
            end: Alignment.topRight,
            colors: [
              Color.fromARGB(255, 254, 172, 94),
              Color.fromARGB(255, 199, 121, 208),
              Color.fromARGB(255, 75, 192, 200),
            ]),
      ),
      child: FutureBuilder(
        future: veriHazirla(),
        builder: (context, sonuc) {
          if (sonuc.hasData) {
            cekilenMasalar = sonuc.data;
            return GridView.builder(
              gridDelegate:
                  SliverGridDelegateWithFixedCrossAxisCount(crossAxisCount: 2),
              itemBuilder: (context, index) {
                return Stack(
                  children: <Widget>[
                    GestureDetector(
                      onTap:() {siparisiGoster(context,cekilenMasalar[index],cekilenMasalar[index].siparis.length-1);},

                      child: Container(
                        padding: EdgeInsets.all(10.0),
                        margin: EdgeInsets.all(10.0),
                        height: 300,
                        width: 300,
                        decoration: BoxDecoration(
                            gradient: LinearGradient(
                                begin: Alignment.bottomLeft,
                                end: Alignment.topRight,
                                colors: renklerigetir(cekilenMasalar[index])),
                            borderRadius: BorderRadius.circular(40)),
                        child: Column(
                          mainAxisAlignment: MainAxisAlignment.center,
                          children: <Widget>[
                            Text(
                              "Masa" + cekilenMasalar[index].masaid.toString(),
                              style: masaText,
                            ),
                            Text(cekilenMasalar[index].tutar.toString() + "TL",
                                style: masaText),
                          ],
                        ),
                      ),
                    ),
                    Align(
                      alignment: Alignment.bottomLeft,
                      child: GestureDetector(
                        child: Stack(
                          children: <Widget>[
                            CircleAvatar(
                              backgroundColor: Colors.black38,
                              radius: 30,
                            ),
                            Icon(
                              Icons.add_circle,
                              size: 60,
                              color: Colors.white70,
                            ),
                          ],
                        ),
                      ),
                    )
                  ],
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


    List<Masa> masalar = (json.decode(gelenJson) as List)
        .map((mapYapisi) => Masa.fromJson(mapYapisi))
        .toList();
    return masalar;
  }

  renklerigetir(Masa masa) {
    List<Color> renkler = [];
    if (masa.masadurumu == true) {
      renkler.add(Color.fromARGB(255, 31, 28, 24));
      renkler.add(Color.fromARGB(255, 142, 14, 0));
    } else {
      renkler.add(Color.fromARGB(255, 31, 28, 24));
      renkler.add(Color.fromARGB(255, 168, 255, 120));
    }
    return renkler;
  }

  siparisiGoster(BuildContext ctx, Masa cekilenMasalar,int index ){
    debugPrint(cekilenMasalar.siparis[index].urunadi);
    showDialog(context: ctx,
      builder: (ctx){
      return AlertDialog(
        title: Text("Siparişler",style:TextStyle(fontSize: 40,color: Colors.white),),
        content: Text(siparisilistele(cekilenMasalar,index),style: TextStyle(fontSize: 30,color: Colors.black),),
        actions: <Widget>[
          FlatButton(
            onPressed: (){
              Navigator.of(ctx).pop();
            }
          )
        ],
        backgroundColor: Colors.deepPurple,
      );
      }



    );
  }

  String siparisilistele(Masa cekilenMasalar, int index) {
    String siparis = "";
    for(int i=0;i<index+1;i++){

      siparis+=cekilenMasalar.siparis[i].adedi.toString()+" "+cekilenMasalar.siparis[i].urunadi.toString()+'\n';


    }
    return siparis;


  }
}


