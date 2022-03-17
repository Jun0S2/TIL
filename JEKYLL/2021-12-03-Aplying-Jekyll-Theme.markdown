---
layout: post
title: "Applying Jekyll Theme"
date: 2021-12-03 16:22:57 +0900
categories: jekyll
---

After some research upon applying theme on github, I managed to at least apply selected theme to the github repository. ~~which I'm still on a journey to find a missing navbar...~~

## Creating and Cloning to Repository

#### 1. Create a new repository

Set Repository name as your github name.github.io `EX: Jun0s2.github.io` <br>

#### 2. Clone git repository to your local folder

```
git init
git clone "https://github.com/name/name.github.io"
```

<hr>

## 2. Install Ruby

Install Ruby via :
<a href = "https://rubyinstaller.org/downloads/">Download Ruby</a>

<hr>

## 3. Install jekyll

After successfully installing Ruby, open command prompt with Ruby

```
search on window for : Start Command Prompt with Ruby
```

<br>
Then, install jekyll with commands below:

```
gem install jekyll bundler
jekyll new ./
bundle install
bundle add webrick
```

<hr>

## 4. Run server

```
bundle exec jekyll serve
```

If the git bash spits out the localhost address successfully but if the server doesnt load properly,
check if you have below warning:
<br>

```
Please add the following to your Gemfile to avoid polling for changes:
gem 'wdm', '>= 0.1.0' if Gem.win_platform?
```

You can fix this by adding wdm and run the server again

```
gem install wdm
```

<hr>

## 5. Select Theme from jekyll

1. <a href="jekyllthemes.org">jekyllthemes.org</a>
2. <a href="https://jekyll-themes.com/">jekyll-themes.com</a>

I selected monophase theme from the first link. ~~and the journey began....~~

## 6. Applying theme to your site

Most of the time, if you go to the theme repository - they kindly give you direction on how to apply the theme.... and sadly it did not quite work for me.
I now don't remember all the errors I've been getting but these were the steps I followed:

1. Download .zip file provided from the theme you selected
2. Unzip all the files and copy & overwrite to your repository
3. follow the instructions

In my case, step 3 gave me some bunch of headaches and these are how I resolved all the errors:

### ADD SEO TAG

Whatever this is, github will first yell at you saying that you don't have seo tag. Not sure if all theme will scream about this but in monophase it surely did...<br>
All you need to do is add seo-tag in config file and Gem file
`Gemfile`:

```
gem "jekyll-seo-tag", "~> 2.6"
```

`config.yml`:

```
plugins:
...
- jekyll-seo-tag
```

### USE REMOTE THEME

Github will scream at you and send you an email telling that they don't support jekyll theme you selected. <br>
`Gemfile` :

```
gem "jekyll-remote-theme"
```

`config.yml`:

```
- jekyll-remote-theme
```

Therefore, if you added any `gem "themename"` in either `Gemfile` or `config.yml` remove these configurations since you will be using remote ones and using plugins instead

Now, cusotmize config files and push it to github to deploy the brand-new-blog-style repository **=^.\_.^=**
