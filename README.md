# SkyWaySFUSample
SkyWay SFU video chat Sample in Swift

SkyWayのSFUを使用したビデオチャットのサンプルです  
アプリ同士で双方向通信、PCはSkyWayのサンプルを使えば接続可能です  

## How to build
Download this repository and move Projects
```
cd SkyWaySFUSample
```

Install library in Cocoapods
```
pod install
```

Open projects in Xcode(then not .xcodeproj but .xcworkspace)
```
open SkyWaySFUSample.xcworkspace
```

Input your API Key
```
ViewController.swift
let apiKey = "***************** Enter your API KEY *******************"
```

Exec Build!

---

If you run this project, not Simulator but actual machine

## ビルド方法
このリポジトリをダウンロード後、プロジェクトに移動
```
cd SkyWaySFUSample
```
Cocoapodsでライブラリをインストール
```
pod install
```

プロジェクトをXcodeで開く（.xcodeprojではなく.xcworkspaceを開く）
```
open SkyWaySFUSample.xcworkspace
```

API Keyを入力
```
ViewController.swift
let apiKey = "***************** Enter your API KEY *******************"
```

ビルドして実行！

---

シミュレーターでは動かないため、実機でテストしてください。

## License
MIT License
