import 'package:flare_flutter/flare.dart';
import 'package:flare_flutter/flare_actor.dart';
import 'package:flare_flutter/flare_render_box.dart';
import 'package:flutter/material.dart';
import 'package:flare_dart/actor.dart';
import 'package:restappi/main.dart';

class HomeScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Scaffold(
        body: Container(
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
      child: Column(
        mainAxisAlignment: MainAxisAlignment.spaceAround,
        mainAxisSize: MainAxisSize.max,
        children: <Widget>[
          GestureDetector(
            //Garson Buton
            onTap: () => {Navigator.pushNamed(context, '/tableScreen')},
            child: Padding(
              padding: const EdgeInsets.fromLTRB(15, 30, 15, 0),
              child: Container(
                decoration: BoxDecoration(
                    borderRadius: BorderRadius.circular(40.0),
                    color: renkGarsonYesil,
                    gradient: LinearGradient(
                        begin: Alignment.bottomLeft,
                        end: Alignment.topRight,
                        colors: [
                          Color.fromARGB(255, 58, 28, 113),
                          Color.fromARGB(255, 205, 109, 119),
                          Color.fromARGB(255, 255, 175, 123)
                        ])),
                height: MediaQuery.of(context).size.height / 2 -
                    50, //Cihaza göre ekran boyutu alma
                width: MediaQuery.of(context).size.width,
                child: Column(
                  children: <Widget>[
                    SizedBox(
                      height: 50,
                    ),
                    Text(
                      "GARSON",
                      style: TextStyle(
                          fontFamily: 'Raleway',
                          fontSize: 75,
                          color: Colors.white),
                      textAlign: TextAlign.center,
                    ),
                    SizedBox(
                        width: 150,
                        height: 150,
                        child: FlareActor("assets/garson.flr",
                            sizeFromArtboard: true,
                            animation: "Untitled",
                            fit: BoxFit.fill)),
                  ],
                ),
              ),
            ),
          ),
          GestureDetector(
            //Mutfak Buton
            onTap: () => {Navigator.pushNamed(context, '/kitchenScreen')},
            child: Padding(
              padding: const EdgeInsets.fromLTRB(15, 30, 15, 30),
              child: Container(
                decoration: BoxDecoration(
                    borderRadius: BorderRadius.circular(40.0),
                    color: renkGarsonYesil,
                    gradient: LinearGradient(
                        begin: Alignment.bottomLeft,
                        end: Alignment.topRight,
                        colors: [
                          Color.fromARGB(255, 69, 104, 220),
                          Color.fromARGB(255, 176, 106, 179)
                        ])),
                height: MediaQuery.of(context).size.height / 2 -
                    50, //Cihaza göre ekran boyutu alma
                width: MediaQuery.of(context).size.width,
                child: Column(
                  children: <Widget>[
                    SizedBox(
                      height: 50,
                    ),
                    Text(
                      "MUTFAK",
                      style: TextStyle(
                          fontFamily: 'Raleway',
                          fontSize: 75,
                          color: Colors.white),
                      textAlign: TextAlign.center,
                    ),
                    SizedBox(
                        width: 270,
                        height: 150,
                        child: FlareActor(
                          "assets/mutfakk.flr",
                          sizeFromArtboard: true,
                          animation: "Yumy",
                          fit: BoxFit.fill,
                        )),
                  ],
                ),
              ),
            ),
          ),
        ],
      ),
    ));
  }
}
