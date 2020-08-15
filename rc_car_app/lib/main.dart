import 'package:flutter/material.dart';

import 'pages/home_screen.dart';
// import 'pages/loading_screen.dart';

void main() => runApp(RCControllerApp());

class RCControllerApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'App Title',
      theme: ThemeData(
        primarySwatch: Colors.blue,
        visualDensity: VisualDensity.adaptivePlatformDensity,
      ),

      // initialRoute: LoadingScreen.routeName, //TODO: Add load logic
      initialRoute: HomeScreen.routeName,
      routes: {
        HomeScreen.routeName: (ctx) => HomeScreen(),
      },
    );
  }
}
