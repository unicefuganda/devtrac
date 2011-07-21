$Id: README.TXT,v 1.1 2010/12/21 06:46:30 batje Exp $

# Description

Questionaire is a set of modules that allow you to dynamically gather simple structured data
and present it in different pre-configured reports.

# Requirements

* Views: http://drupal.org/project/views
* Associated Nodes: http://drupal.org/project/associated_nodes (with patch http://drupal.org/node/1003994 )
* Views Charts: http://drupal.org/project/views_charts
* Views Group By: http://drupal.org/project/views_groupby
* Features: http://drupal.org/project/features

# Basic Concepts

## Questionaire
In the current version, any nodetype can be of type Questionaire. When you see a node that is marked being 
a Questionaire, and relevant Questions or Answers are available, a menu called Questions will appear that 
gives you access to the Questions for that Questionaire.

## Questions
Questions is a node type that this module implements. There are different types of questions. Currently:

- number
- select
- checkboxes
- radio
- time

When you create a question, you select the type, and when relevant can also provide options. On option per line. 
The module so far is not multi-lingual, so Cookie and Koekje are too different answers.

## Context
The context for Questionaire is the node to which the Questions apply. This does not necessarily have to be the Questionaire!
By default this is the case, but there is a hook (hook_getcontext) that allows you to override this, for example by returning 
the value of a nodereference field. (for example, you have purchased a CD. When you look at your purchase, we would like you to 
answer a question about the CD. Then Purchase is the Questionaire, CD is the context. Another example is if you have to write
a report about a school or a waterpoint or a health center. The Report is the Questionaire, but the S/W/HC is the context.)  

## Submissions
Every time a user submits 1 or more questions in one go, we call that a submission. Currently users can submit 
questions as often as they want, and they do not have to provide all questions when they submit.

## Answers
Each answered question is stored as an Answer. For Checkboxes, when multiple boxes are checker, multiple Answers are stored.
All Answers go into 1 table, from which we generate all reports and overviews. 


# Installation

1. Normal Drupal module installation

2. Enable the module questionaire_question. For now the questionaire module is not available, it will contain a nodetype
that provides simple questionaire design and builds on top of questionaire_question. (you see, the Question module was taken)

2. Apply the supplied patch to Associated Nodes http://drupal.org/node/1003994

3. Create a nodetype for your Questionaires and mark the Nodetype as such under the Questionaire Fieldgroup

4. If your Questionaire == Your context, make sure your content type has a vocabulary enabled or a CCK field

5. Enable/Add the same Vocabulary or CCK field to the Question nodetype

6. Create 1 Node Association for Question, that has (for now) to be the first one with id 1 !!

7. Create a Question & a Context

8. Navigate to the Context and click the Question tab. 

9. Click the Submission Tab, fill in the form and submit

10. On the Question tab, click any of the Questions and see the results.


## Disclaimer
We think this is a cool module that does add on to Drupal, even though there is already webform, cck etc. 
Being able to dynamically assign Questions and to re-use questions between Questionaires is something that
this module adds for example.

We just started developing, and we need to do a lot more. This version has bugs, we know that, and we will squash them.
This release is a preview for people who are interested and daring. If you like it enough to help developing, or you 
have a project where you would like to use this and you need a hand, let us know.


## Credits

* [batje](http://drupal.org/user/2696)
* [Jan van Diepen](http://drupal.org/user/195578)

 
