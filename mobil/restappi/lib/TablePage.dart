import 'dart:ui' as prefix0;

import 'package:flare_flutter/flare_actor.dart';
import 'package:flutter/material.dart';
import 'package:restappi/main.dart';

class TablePages extends StatefulWidget {
  @override
  State<StatefulWidget> createState() {
    // TODO: implement createState
    return tablePageState();
  }
}

// ignore: camel_case_types
class tablePageState extends State {
  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Container(
      decoration: BoxDecoration(
        gradient: LinearGradient(
            colors: [renkGarsonYesil, Color.fromARGB(255, 74, 0, 224)]),
      ),
    );
  }
}
