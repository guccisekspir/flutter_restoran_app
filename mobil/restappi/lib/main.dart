import 'dart:async';

import 'package:flare_flutter/flare_actor.dart';
import 'package:flutter/material.dart';
import 'package:flare_flutter/flare.dart';
import 'package:restappi/HomeScreen.dart';
import 'package:restappi/KitchenPage.dart';
import 'package:restappi/TablePage.dart';
import 'package:restappi/splashscreen.dart';
import 'package:flutter/services.dart';

Color renkArka = Color.fromARGB(255, 1, 135, 134);
Color renkGarsonYesil = Color.fromARGB(255, 98, 0, 238);
Color renkMutfakSari = Color.fromARGB(255, 1444, 44, 65);
Color renkKirmizi = Color.fromARGB(255, 199, 13, 58);

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(

      debugShowCheckedModeBanner: false,
      title: "RestAppi",
      initialRoute: '/',
      routes: {
        '/homeScreen' : (context)=> HomeScreen(),
        '/kitchenScreen': (context)=> KitchenPage(),
        '/tableScreen':(context)=> TablePages(),
      },
      home: SplashScreen()
    );
  }
}

class SplashScreen extends StatefulWidget{

  @override
  State<StatefulWidget> createState() {
    // TODO: implement createState
    return SplashScreenState();
  }
}


class SplashScreenState extends State{

  var deneme =2;

  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Scaffold(
      body: FlareActor("assets/foodeals.flr",animation: "intro", fit: BoxFit.fill,),
    );
  }

  @override
  void initState(){
    super.initState();
    startTime();
  }
  startTime() async{
    var _duration = Duration(seconds: 4);
    return Timer(_duration,navigatorPush);
  }
  navigatorPush(){
    Navigator.pushNamedAndRemoveUntil(context, '/homeScreen', (Route<dynamic> route) => false);
  }

}

