---
layout: post
title: "Jekyll Error Resolution Logs"
date: 2021-12-03 16:22:57 +0900
categories: jekyll
---

## Error resolved

### 1. wdm installation

bundle exec jekyll serve failure

1. Error Logs:

```
Please add the following to your Gemfile to avoid polling for changes:
gem 'wdm', '>= 0.1.0' if Gem.win_platform?
```

2. Solution :

```
gem install wdm
```

Reference :<a href = "https://stackoverflow.com/questions/32723710/add-line-of-code-to-gemfile-that-already-contains-that-line-of-code"> stackoverflow</a>

### 2. webrick installation

bundle exec jekyll serve failure

1. Error Logs :

```
  ...in `require': cannot load such file -- webrick (LoadError)
```

2. Solution :

```
bundle add webrick
```

Reference : <a href= "https://github.com/jekyll/jekyll/issues/8523">jekyll issue forums</a>
